#include <stdio.h>
#include <assert.h>
#include "presentation.h"
// #include "options.h" // FIXME
#include "file.h"
// #include "presenter.h"
#include "list.h"

extern int parser_parse(Presentation *pres, char *filename);

int main(int argc, char *argv[])
{
	// create a new presentation
	Presentation* p = presentation_new();
	assert(p);

	// read options from command line
     	// Options* options = options_get(p, argc, argv); FIXME
	p->filename = "tmp.xsw";
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
	/*
	int current = 0;
	if(options->last)
		current = p->n_slides - 1;
	int running = 1;
	Presenter* pr = presenter_initialize(p, 1);
	if(!pr)
		return 1; // message was already given in the function
	presenter_cache(pr, current);
	presenter_show(pr, current, options->developer);

	while(running)
	{
		switch(presenter_get_event())
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
					presenter_show(pr, current, options->developer);
				}
				break;

			case PRESENTER_PREVIOUS:
				if(current > 0)
				{
					current--;
					presenter_cache(pr, current);
					presenter_show(pr, current, options->developer);
				}
				break;

			case PRESENTER_FIRST:
				current = 0;
				presenter_cache(pr, current);
				presenter_show(pr, current, options->developer);
				break;

			case PRESENTER_LAST:
				current = p->n_slides - 1;
				presenter_cache(pr, current);
				presenter_show(pr, current, options->developer);
				break;

			case PRESENTER_DEVELOPER:
				options->developer = !options->developer;
				presenter_show(pr, current, options->developer);
				break;

			default:
				abort();
		}
	}
	presenter_quit();
	*/

	// exit
	return 0;
}
