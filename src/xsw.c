#include <stdio.h>
#include "presentation.h"
#include "options.h"
#include "file.h"
#include "xpresenter.h"
#include "images.h"

extern int parser_parse(Presentation *pres, char *filename);

int main(int argc, char* argv[])
{
	Presentation* presentation = presentation_new();

	// read options from command line
     	options_get(presentation, argc, argv);

	// read file - TODO test if file exists
	
	// parse
	if(!parser_parse(presentation, presentation->filename))
	{
		fprintf(stderr, "Invalid SSW file.");
		return 1;
	}

	// process images
	images_process(presentation);

	// show
	presenter_show(presentation);

	// exit
	return 0;
}
