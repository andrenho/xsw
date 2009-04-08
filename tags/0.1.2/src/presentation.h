#ifndef PRESENTATION_H
#define PRESENTATION_H

#ifdef USE_SDL
#include "SDL.h"
#endif

#include "list.h"
#include "slide.h"

// commands
typedef struct CommandText {
	char* text; // NULL means template
	double x, y, w, h;
	char* template_name;
	char* font;
	double size;
	int italic;
	int align;
	int _continue;
	struct CommandText* previous;
#ifdef USE_SDL
	SDL_Surface* surface;
	SDL_Surface* surface_inv;
#endif
} CommandText;

typedef struct {
	char* path;
	int x, y, w, h;
	double scale;
	int background;
	int expand_horiz;
#ifdef USE_SDL
	SDL_Surface* surface;
#endif
} CommandImage;

typedef union {
	CommandText text;
	CommandImage image;
} CommandUnion;

typedef struct {
	enum { T_TEXT, T_IMAGE } type;
	CommandUnion command;
	int dirty;
} Command;

// --

typedef struct {
	char* filename;
	List* slides;
	List* templates;
} Presentation;

Presentation* presentation_new();
void pr_add_slide(Presentation* p, Slide* sl);
void pr_add_slide_from(Presentation* p, Slide* sl, char* template_id);

#endif
