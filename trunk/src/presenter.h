/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#ifndef PRESENTER_H
#define PRESENTER_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "presentation.h"

#define SCR_W 800
#define SCR_H 600

typedef enum { PRESENTER_QUIT, PRESENTER_FULLSCREEN, PRESENTER_NEXT, 
	PRESENTER_PREVIOUS, PRESENTER_FIRST, PRESENTER_LAST, PRESENTER_DEVELOPER,
	PRESENTER_NO_EVENT } PresenterEvent;

typedef struct {
	SDL_Surface* scr;
	TTF_Font* font;
	Presentation* p;
	int fullscreen;
} Presenter;

Presenter* presenter_initialize(Presentation* p, int initialize_video);
void presenter_cache(Presenter* pr, int slide);
int presenter_cache_next(Presenter* pr);
void presenter_show(Presenter* pr, int slide, int developer);
PresenterEvent presenter_get_event(Presenter* pr, int developer, int w);
void presenter_fullscreen(Presenter* pr, int developer);
void presenter_save_image(Presenter* pr, char* filename);
void presenter_quit();

#endif
