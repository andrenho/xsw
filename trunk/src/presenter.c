#include <assert.h>
#include <stdlib.h>
#include "presenter.h"
#include "command.h"

Presenter* presenter_initialize(Presentation* p, int initialize_video)
{
	int st;
	Presenter* pr = malloc(sizeof(Presenter));
	pr->p = p;
	pr->thread = NULL;
	pr->leave_thread = 0;
	pr->thread_running = 0;
	
	if(initialize_video)
		st = SDL_Init(SDL_INIT_VIDEO);
	else
		st = SDL_Init(0);

	if(st == -1)
		fprintf(stderr, "Could not initialize SDL: %s.\n", SDL_GetError());

	if(initialize_video)
	{
		pr->scr = SDL_SetVideoMode(800, 600, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
		if(pr->scr == 0)
		{
			fprintf(stderr, "Could not set video mode: %s.\n", SDL_GetError());
			return 0;
		}
		SDL_FillRect(pr->scr, NULL, SDL_MapRGB(pr->scr->format, 255, 255, 255));
		SDL_Flip(pr->scr);
	}

	return pr;
}

static int presenter_cache_thread(void* p_pr)
{
	Presenter* pr = (Presenter*)p_pr;
	int i, j;

	pr->thread_running = 1;
	pr->leave_thread = 0;

	for(i=0; i<pr->p->n_slides; i++)
		for(j=0; j<pr->p->slides[i]->n_commands; j++)
		{
			if(pr->leave_thread)
			{
				pr->thread_running = 0;
				return 1;
			}
			if(pr->p->slides[i]->commands[j]->dirty)
				command_parse(pr->p->slides[i]->commands[j]);
		}

	pr->thread_running = 0;
	return 0;
}

void presenter_cache(Presenter* pr, int slide)
{
	assert(slide < pr->p->n_slides);
	int i;

	// if the thread is running, we tell it to leave
	if(pr->thread_running)
	{
		pr->leave_thread = 1;
		SDL_WaitThread(pr->thread, NULL);
	}

	// load the required slide images outside the thread
	for(i=0; i<pr->p->slides[slide]->n_commands; i++)
		command_parse(pr->p->slides[slide]->commands[i]);

	// load the rest of the images from the thread
	pr->thread = SDL_CreateThread(presenter_cache_thread, pr);
}

void presenter_show(Presenter* pr, int slide)
{
}

PresenterEvent presenter_get_event(Presenter* pr)
{
	SDL_Event e;

	for(;;)
	{
		SDL_WaitEvent(&e);
		switch(e.type)
		{
		case SDL_QUIT:
			return PRESENTER_QUIT;

		case SDL_KEYDOWN:
			switch(e.key.keysym.sym)
			{
			case SDLK_q:
				return PRESENTER_QUIT;
			case SDLK_PAGEUP:
			case SDLK_UP:
			case SDLK_LEFT:
				return PRESENTER_PREVIOUS;
			case SDLK_PAGEDOWN:
			case SDLK_DOWN:
			case SDLK_RIGHT:
				return PRESENTER_NEXT;
			case SDLK_f:
				return PRESENTER_FULLSCREEN;
			}				
		}
	}
}

void presenter_fullscreen(Presenter* pr)
{
	SDL_WM_ToggleFullScreen(pr->scr);
}

void presenter_quit(Presenter* pr)
{
	SDL_Quit();
}
