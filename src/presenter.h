#ifndef PRESENTER_H
#define PRESENTER_H

#include "SDL.h"
#include "presentation.h"

typedef enum { PRESENTER_QUIT, PRESENTER_FULLSCREEN, PRESENTER_NEXT, PRESENTER_PREVIOUS } PresenterEvent;

typedef struct {
	SDL_Surface* scr;
	SDL_Thread* thread;
	int leave_thread;
	int thread_running;
	Presentation* p;
} Presenter;

Presenter* presenter_initialize(Presentation* p, int initialize_video);
void presenter_cache(Presenter* pr, int slide);
void presenter_show(Presenter* pr, int slide);
PresenterEvent presenter_get_event(Presenter* pr);
void presenter_fullscreen(Presenter* pr);
void presenter_quit(Presenter* pr);

#endif
