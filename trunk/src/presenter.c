#include "presenter.h"

Presenter* presenter_initialize(Presentation* p, int initialize_video)
{
	int st;
	Presenter* pr = malloc(sizeof(Presenter));
	
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
			fprintf("Could not set video mode: %s.\n", SDL_GetError());
			return 0;
		}
	}

	return pr;
}


void presenter_cache(Presenter* pr, int slide)
{
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
