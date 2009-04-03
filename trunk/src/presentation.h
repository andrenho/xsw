#ifndef PRESENTATION_H
#define PRESENTATION_H

#ifdef USE_SDL
#include "SDL.h"
#endif

#define SLIDES_LIMIT 1024
#define COMMANDS_LIMIT 1024

// commands
typedef struct {
	char* text;
	int x, y, w, h;
	double size;
} CommandText;

typedef struct {
	char* path;
	int x, y, w, h;
	double scale;
} CommandImage;

typedef struct {
	char* path;
	enum { full, horizontal, vertical } anchor;
} CommandBackground;

typedef union {
	CommandText text;
	CommandImage image;
	CommandBackground background;
} CommandUnion;

typedef struct {
	enum { T_TEXT, T_IMAGE } type;
	CommandUnion command;
	int dirty;
#ifdef USE_SDL
	SDL_Surface* surface;
#endif
} Command;

// --

typedef struct {
	Command* commands[COMMANDS_LIMIT];
	int n_commands;
} Slide;

typedef struct {
	char* filename;
	Slide* slides[SLIDES_LIMIT];
	int n_slides;
} Presentation;

Presentation* presentation_new();
Slide* presentation_add_slide(Presentation* presentation);
CommandText* slide_add_text_command(Slide* slide, char* text, CommandText* cmd_txt);
CommandImage* slide_add_image_command(Slide* slide, char* path);

#endif
