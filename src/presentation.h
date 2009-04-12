#ifndef PRESENTATION_H
#define PRESENTATION_H

#ifdef USE_SDL
#include "SDL.h"
#endif

#include "list.h"
#include "slide.h"

typedef struct {
	char* filename;
	char* path;
	List* slides;
	List* templates;
	char* image_path;
} Presentation;

Presentation* presentation_new();
Slide* pr_add_slide(Presentation* p, Slide* sl);
Slide* pr_add_slide_from(Presentation* p, Slide* sl, char* template_id);

#endif
