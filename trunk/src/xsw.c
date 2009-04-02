#include <stdio.h>
#include "presentation.h"
#include "options.h"
#include "file.h"
#include "presenter.h"

extern int parser_parse(Presentation *pres, char *filename);

int main(int argc, char *argv[])
{
	Presentation* presentation = presentation_new();

#ifndef __TINYC__
	// read options from command line
     	options_get(presentation, argc, argv);
#else
	presentation->filename = "tmp.xsw";
#endif

	// read file - TODO test if file exists
	
	// parse
	if(!parser_parse(presentation, presentation->filename))
	{
		fprintf(stderr, "Invalid SSW file.");
		return 1;
	}

	// show
	int current = 0;
	int running = 1;
	Presenter* pr = presenter_initialize(presentation, 1);
	if(!pr)
		return 1;
	presenter_cache(pr, current);
	presenter_show(pr, current);
	while(running)
	{
		switch(presenter_get_event(pr))
		{
			case PRESENTER_QUIT:
				running = 0;
				break;

			case PRESENTER_FULLSCREEN:
				presenter_fullscreen(pr);
				break;

			case PRESENTER_NEXT:
				if(current < presentation->n_slides)
				{
					current++;
					presenter_cache(pr, current);
					presenter_show(pr, current);
				}
				break;

			case PRESENTER_PREVIOUS:
				if(current >= 0)
				{
					current--;
					presenter_cache(pr, current);
					presenter_show(pr, current);
				}
				break;

			default:
				abort();
		}
	}
	presenter_quit(pr);

	// exit
	return 0;
}
