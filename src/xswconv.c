#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "presentation.h"
#include "presenter.h"
#include "slide.h"
#include "file.h"
#include "presenter.h"
#include "parser.h"

typedef enum { none, pdf, png, jpg } t_format;

typedef struct {
	t_format format;
	char* output_file;
	char* filename;
} ConvOptions;

extern int parser_parse(Presentation *pres, char *filename);

static int check_convert()
{
	if(system("convert > /dev/null") == 32512)
		return 0;
	return 1;
}

static void print_usage(FILE* stream)
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
	fprintf(stream, "  pdf        Portable Document Format (one file per presentation)\n");
	fprintf(stream, "  png        Portable Network Graphics (one file per slide)\n");
	fprintf(stream, "  jpeg       JPEG interchange format (one file per slide)\n");
}

static ConvOptions* parse_options(int argc, char** argv)
{
	opt = malloc(sizeof(ConvOptions));
	opt->format = none;
	opt->output_file = NULL;
	opt->filename = NULL;

	return op;
}

int main(int argc, char** argv)
{
	// check parameters
	ConvOptions *opt = parse_options(argc, argv);
	if(opt->format == none || !opt->output_file || !opt->filename)
	{
		print_usage(stderr);
		return 1;
	}

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
