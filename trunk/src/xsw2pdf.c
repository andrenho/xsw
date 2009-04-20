#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "presentation.h"
#include "presenter.h"
#include "slide.h"
#include "file.h"
#include "presenter.h"
#include "parser.h"

extern int parser_parse(Presentation *pres, char *filename);

static int check_convert()
{
	if(system("convert > /dev/null") == 32512)
		return 0;
	return 1;
}

static void print_usage()
{
	fprintf(stdout, "xsw2pdf version " VERSION "\n");
	fprintf(stdout, "Usage: xsw2pdf FILE\n");
	fprintf(stdout, "Convert a xsw presentation into a PDF file.\n");
}

int main(int argc, char** argv)
{
	// check parameters
	if(argc != 2)
	{
		print_usage();
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
	sprintf(path, "/tmp/%s", "xsw-XXXXXX");
	path = mkdtemp(path);

	// load slideshow
	Presenter* pr = presenter_initialize(p, 0);
	int slides = count(p->slides);
	int i;
	char* all_bmp = alloca(slides * 25); // TODO
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
	char* name = alloca(512);
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
