#include <stdio.h>
#include "presentation.h"
#include "options.h"
#include "file.h"

extern int parser_parse(Presentation *pres, char *filename);

int main(int argc, char* argv[])
{
	Presentation* presentation = presentation_new();

	// read options from command line
     	options_get(presentation, argc, argv);

	// read file
//	char* sswl;
// 	sswl = file_read(presentation->filename);
//	sswl = file_read("test.sswl");
	
	// parse
	if(!parser_parse(presentation, presentation->filename))
	{
		fprintf(stderr, "Invalid SSW file.");
		return 1;
	}

	// show
	presenter_show(presentation);

	// exit
	return 0;
}
