/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <stdio.h>
#include <assert.h>
#include "presentation.h"
#include "options.h"
#include "file.h"
#include "presenter.h"
#include "list.h"

extern int parser_parse(Presentation *pres, char *filename);

int main(int argc, char *argv[])
{
	// create a new presentation
	Presentation* p = presentation_new();
	assert(p);

	// read options from command line
     	Options* options = options_get(p, argc, argv);
	// p->filename = "tmp.xsw";
	assert(p);
	assert(p->filename);

	// read file - test if file exists
	if(!file_exists(p->filename))
	{
		fprintf(stderr, "%s is not a valid file.\n", p->filename);
		return 1;
	}

	// get file path
	p->path = file_path(p->filename);
	
	// parse code in the file
	if(!parser_parse(p, p->filename))
	{
		fprintf(stderr, "Invalid XSW file.\n");
		return 1;
	}

	// go to the slide n?
	int current = 0;
	if(options->starting_slide != 0)
	{
		if(options->starting_slide < 0)
		{
			fprintf(stderr, "The starting slide must be > 0.\n");
			return 1;
		}
		else if(options->starting_slide > lcount(p->slides))
		{
			fprintf(stderr, "This presentation only has %d slides.\n", lcount(p->slides));
			return 1;
		}
		current = options->starting_slide - 1;
	}
	
	// go to the last slide?
	if(options->last)
		current = lcount(p->slides) - 1;

	// present slideshow
	Presenter* pr = presenter_initialize(p, options->fullscreen ? 2 : 1);
	if(!pr)
		return 1; // message was already given in the function
	presenter_show(pr, current, options->developer);

	int all_cached = 0;
	while(1 /*running*/)
	{
		switch(presenter_get_event(pr, options->developer, all_cached))
		{
			case PRESENTER_QUIT:
				// running = 0;
				printf("Quitting.\n");
				presenter_quit();
				return 0;

			case PRESENTER_FULLSCREEN:
				presenter_fullscreen(pr, options->developer);
				break;

			case PRESENTER_NEXT:
				if(current < lcount(p->slides)-1)
				{
					current++;
					presenter_show(pr, current, options->developer);
				}
				break;

			case PRESENTER_PREVIOUS:
				if(current > 0)
				{
					current--;
					presenter_show(pr, current, options->developer);
				}
				break;

			case PRESENTER_FIRST:
				current = 0;
				presenter_show(pr, current, options->developer);
				break;

			case PRESENTER_LAST:
				current = lcount(p->slides) - 1;
				presenter_show(pr, current, options->developer);
				break;

			case PRESENTER_DEVELOPER:
				options->developer = !options->developer;
				presenter_show(pr, current, options->developer);
				break;

			case PRESENTER_NO_EVENT:
				break;
		}
		if(!all_cached)
			all_cached = presenter_cache_next(pr);
	}
//	presenter_quit();

	// exit
//	return 0;
}
