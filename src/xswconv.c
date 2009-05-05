#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <string.h>
#include "presentation.h"
#include "presenter.h"
#include "slide.h"
#include "file.h"
#include "presenter.h"
#include "parser.h"

extern int parser_parse(Presentation *pres, char *filename);


// 
// available formats
//
typedef enum { none, pdf, png, jpeg } t_format;

typedef struct {
	char* desc;
	t_format format;
	char* extension;
	int one_per_slide;
} t_type;

static const t_type const types[] = {
	{ "none", none, "none", 0 },
	{ "pdf", pdf, "pdf", 0 },
	{ "png", png, "png", 1 },
	{ "jpeg", jpeg, "jpg", 1 }
};

#define TYPE_NONE types[0];
#define N_TYPES (sizeof(types) / sizeof(*types))

// 
// user options
//
typedef struct {
	t_type type;
	char* output_file;
	char* filename;
} ConvOptions;


// 
// check if the utility 'convert' is installed
//
static int check_convert()
{
	if(system("convert > /dev/null") == 32512)
		return 0;
	return 1;
}

// 
// print tool usage
//
static void print_usage(FILE* stream, int exit_value)
{
	fprintf(stream, "xswconv version " VERSION "\n");
	fprintf(stream, "Usage: xswconv [OPTIONS] FILE\n");
	fprintf(stream, "Convert a xsw presentation into a different format.\n");
	fprintf(stream, "\n");
	fprintf(stream, "Options:\n");
	fprintf(stream, "  -f, --format=FORMAT     output format (see below)\n");
	fprintf(stream, "  -o, --output=FILE       output file/directory name\n");
	fprintf(stream, "\n");
	fprintf(stream, "Formats:\n");
	fprintf(stream, "   pdf       Portable Document Format (one file per presentation)\n");
	fprintf(stream, "   png       Portable Network Graphics (one file per slide)\n");
	fprintf(stream, "  jpeg       JPEG interchange format (one file per slide)\n");

	exit(exit_value);
}


// 
// print tool version
//
static void print_version(FILE* stream, int exit_code)
{
	fprintf(stream, "xswconv " VERSION ", a xsw converter tool.\n");
	fprintf(stream, "xsw and xswconv are free softwares.\n");
	fprintf(stream, "Copyleft (C) 2009 André Wagner <andre.nho@gmail.com> - all wrongs reserved\n");
	exit(exit_code);
}


// 
// parse the options given by the user
//
static ConvOptions* parse_options(int argc, char** argv)
{
	int next_option;
	unsigned int i;

	ConvOptions* opt = malloc(sizeof(ConvOptions));
	opt->type = TYPE_NONE;
	opt->output_file = NULL;
	opt->filename = NULL;

	const char* const short_options = "hvf:o:";
	const struct option long_options[] = {
		{ "help", 0, NULL, 'h' },
		{ "version", 0, NULL, 'v' },
		{ "format", 1, NULL, 'f' },
		{ "output", 1, NULL, 'o' },
		{ NULL, 0, NULL, 0 }
	};

	do 
	{
		next_option = getopt_long(argc, argv, short_options, 
				long_options, NULL);
		switch(next_option)
		{
			case '?':
				print_usage(stderr, 1);
				break;
			case -1: // done
				break;
			case 'h':
				print_usage(stdout, 0);
			case 'v':
				print_version(stdout, 0);
			case 'f':
				for(i=0; i<N_TYPES; i++)
					if(strcmp(optarg, types[i].desc) == 0)
						opt->type = types[i];
				break;
			case 'o':
				opt->output_file = strdup(optarg);
				break;
			default:
				abort();
		}
	} while (next_option != -1);

	if(argc > optind)
		opt->filename = argv[optind];

	if(!opt->output_file)
		opt->output_file = base_name(opt->filename);

	return opt;
}


// 
// parse options and generate the files
//
int main(int argc, char** argv)
{
	// check parameters
	ConvOptions *opt = parse_options(argc, argv);
	if(opt->type.format == none || !opt->output_file || !opt->filename)
		print_usage(stderr, 1);

	printf("%s %s %s\n", opt->type.desc, opt->output_file, opt->filename);
	return 0;

	// check for 'convert'
	if(!check_convert())
	{
		fprintf(stderr, "Sorry, the 'convert' program was not found. It is part of the ImageMagick\ntools. You can get it at: <http://www.imagemagick.org/>\n");
		return 1;
	}

	// load presentation
	Presentation* p = presentation_new();
	p->filename = argv[1];
	if(!file_exists(p->filename))
	{
		fprintf(stderr, "%s is not a valid file.\n", p->filename);
		return 1;
	}
	p->path = file_path(p->filename);

	// parse code in the file
	if(!parser_parse(p, p->filename))
	{
		fprintf(stderr, "Invalid XSW file.\n");
		return 1;
	}

	// prepare temporary directory
	char* path = alloca(20);
	if (path == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	sprintf(path, "/tmp/%s", "xsw-XXXXXX");
	path = mkdtemp(path);

	// load slideshow
	Presenter* pr = presenter_initialize(p, 0);
	int slides = count(p->slides);
	int i;
	char* all_bmp = alloca(slides * 25); // TODO
	if (all_bmp == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	strcpy(all_bmp, "");
	for(i=0; i<slides; i++)
	{
		char bmp_path[512];
		sprintf(bmp_path, "%s/%d.bmp", path, i);
		presenter_show(pr, i, 0);
		presenter_save_image(pr, bmp_path);
		strcat(all_bmp, bmp_path);
		strcat(all_bmp, " ");
	}

	// generate pdf
	char* command = alloca(strlen(all_bmp) + 512);
	if (command == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	char* name = alloca(512);
	if (name == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	sprintf(name, "%s.pdf", base_name(p->filename));
	printf("Generating %s...\n", name);
	sprintf(command, "convert -compress Zip %s %s", all_bmp, name);
	if(system(command) != 0)
	{
		printf("error!\n");
		fprintf(stderr, "There was an error when running 'convert'.\n");
		return 1;
	}

	// remove files
	printf("Removing temporary files...\n");
	for(i=0; i<slides; i++)
	{
		char bmp_path[512];
		sprintf(bmp_path, "%s/%d.bmp", path, i);
		unlink(bmp_path);
	}
	rmdir(path);

	return 0;
}
