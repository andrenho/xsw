#ifndef PRESENTER_H
#define PRESENTER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "presentation.h"

#define SCR_W 800
#define SCR_H 600

typedef enum { PRESENTER_QUIT, PRESENTER_FULLSCREEN, PRESENTER_NEXT, PRESENTER_PREVIOUS, PRESENTER_FIRST, PRESENTER_LAST } PresenterEvent;

typedef struct {
	SDL_Surface* scr;
	SDL_Thread* thread;
	int leave_thread;
	int thread_running;
	TTF_Font* font;
	Presentation* p;
} Presenter;

Presenter* presenter_initialize(Presentation* p, int initialize_video);
void presenter_cache(Presenter* pr, int slide);
void presenter_show(Presenter* pr, int slide, int developer);
PresenterEvent presenter_get_event();
void presenter_fullscreen(Presenter* pr);
void presenter_quit();

#endif
