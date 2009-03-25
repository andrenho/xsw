#include <stdio.h>
#include "presentation.h"
#include "options.h"
#include "parser.h"
#include "file.h"

int main(int argc, char* argv[])
{
	Presentation* presentation = presentation_new();

	// read options from command line
       	options_get(presentation, argc, argv);

	// read file
	char* sswl;
	sswl = file_read(presentation->filename);
	// sswl = file_read("test.sswl");
	
	// parse
	if(!parser_parse(presentation, sswl))
	{
		fprintf(stderr, "Invalid SSW file.");
		return 1;
	}

	// exit
	return 0;
}
