#include <stdio.h>
#include <assert.h>
#include "presentation.h"
#include "options.h"
#include "file.h"
#include "presenter.h"

extern int parser_parse(Presentation *pres, char *filename);

int main(int argc, char *argv[])
{
	// create a new presentation
	Presentation* p = presentation_new();
	assert(p);

	// read options from command line
     	options_get(p, argc, argv);
	assert(p);
	assert(p->filename);

	// read file - test if file exists
	if(!file_exists(p->filename))
	{
		fprintf(stderr, "%s is not a valid file.\n", p->filename);
		return 1;
	}
	
	// parse code in the file
	if(!parser_parse(p, p->filename))
	{
		fprintf(stderr, "Invalid SSW file.");
		return 1;
	}

	// present slideshow
	int current = 0;
	int running = 1;
	Presenter* pr = presenter_initialize(p, 1);
	if(!pr)
		return 1; // message was already given in the function
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
				if(current < (p->n_slides-1))
				{
					current++;
					presenter_cache(pr, current);
					presenter_show(pr, current);
				}
				break;

			case PRESENTER_PREVIOUS:
				if(current > 0)
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
