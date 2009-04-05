#include <assert.h>
#include <stdlib.h>
#include "SDL_ttf.h"
#include "presenter.h"
#include "command.h"

inline static void clear_screen(SDL_Surface* scr)
{
	SDL_FillRect(scr, NULL, SDL_MapRGB(scr->format, 0, 0, 0));
}

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
			return NULL;
		}
		SDL_WM_SetCaption("xsw", "xsw");
		clear_screen(pr->scr);
		SDL_Flip(pr->scr);
	}

	if(TTF_Init() == -1)
	{
		fprintf(stderr, "Error initializing SDL_ttf: %s.\n", TTF_GetError());
		return NULL;
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
				command_parse(pr, pr->p->slides[i]->commands[j]);
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
		command_parse(pr, pr->p->slides[slide]->commands[i]);

	// load the rest of the images from the thread
	pr->thread = SDL_CreateThread(presenter_cache_thread, pr);
}

void presenter_show(Presenter* pr, int slide, int developer)
{
	int i;
	CommandImage* img;
	CommandText* txt;
	SDL_Rect r;

	clear_screen(pr->scr);

	for(i=0; i<pr->p->slides[slide]->n_commands; i++)
	{
		Command* cmd = pr->p->slides[slide]->commands[i];
		switch(cmd->type)
		{
		case T_IMAGE:
			img = &cmd->command.image;
			r.x = (float)img->x / 100.0 * pr->scr->w;
			r.y = (float)img->y / 75.0 * pr->scr->h;
			SDL_BlitSurface(img->surface, NULL, pr->scr, &r);
			break;
		case T_TEXT:
			txt = &cmd->command.text;
			r.x = (float)txt->x / 100.0 * pr->scr->w-1;
			if(txt->align_right)
				r.x -= txt->surface->w;
			r.y = (float)txt->y / 75.0 * pr->scr->h;

			SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &r);
			r.x += 2;
			SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &r);
			r.x -= 1;
			r.y -= 1;
			SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &r);
			r.y += 2;
			SDL_BlitSurface(txt->surface_inv, NULL, pr->scr, &r);
			r.y -= 1;
			SDL_BlitSurface(txt->surface, NULL, pr->scr, &r);
			break;
		default:
			abort();
		}
	}

	if(developer)
	{
		int i;
		Uint32 white = SDL_MapRGB(pr->scr->format, 255, 255, 255);

		// vertical lines
		for(i=10; i<100; i+=10)
		{
			r.x = (float)i / 100.0 * SCR_W;
			r.y = 0;
			r.h = SCR_H;
			r.w = 1;
			SDL_FillRect(pr->scr, &r, 0);
			r.x++;
			SDL_FillRect(pr->scr, &r, white);
		}

		// horizontal lines
		for(i=10; i<80; i+=10)
		{
			r.y = (float)i / 100.0 * SCR_W;
			r.x = 0;
			r.w = SCR_W;
			r.h = 1;
			SDL_FillRect(pr->scr, &r, 0);
			r.x++;
			SDL_FillRect(pr->scr, &r, white);
		}
	}

	SDL_Flip(pr->scr);

	// FIXME - free stuff?
}

PresenterEvent presenter_get_event()
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
			case SDLK_HOME:
				return PRESENTER_FIRST;
			case SDLK_END:
				return PRESENTER_LAST;
			case SDLK_f:
				return PRESENTER_FULLSCREEN;
			default:
				break;
			}				
		}
	}
}

void presenter_fullscreen(Presenter* pr)
{
	SDL_WM_ToggleFullScreen(pr->scr);
}

void presenter_quit()
{
	SDL_Quit();
}
