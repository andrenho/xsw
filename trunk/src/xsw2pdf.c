#include <stdio.h>
#include <stdlib.h>
#include "presentation.h"
#include "presenter.h"
#include "slide.h"

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
	sprintf(path, "%s", "xsw-XXXXXX");
	path = mkdtemp(path);
	printf("%s\n", path);
	return 0;

	// load slideshow
	Presenter* pr = presenter_initialize(p, 0);
	int slides = count(p->slides);
	int i;
	for(i=0; i<slides; i++)
	{
		presenter_show(pr, i, 0);

	}

	return 0;
}
