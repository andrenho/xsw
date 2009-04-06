#ifndef PRESENTATION_H
#define PRESENTATION_H

#ifdef USE_SDL
#include "SDL.h"
#endif

#define SLIDES_LIMIT 1024
#define COMMANDS_LIMIT 1024

#define LINESKIP -31241

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
} Command;

// --

typedef struct Slide {
	Command* commands[COMMANDS_LIMIT];
	int n_commands;
	char* name;
	struct Slide* parent;
} Slide;

typedef struct {
	char* filename;
	Slide* slides[SLIDES_LIMIT];
	int n_slides;
	Slide* templates[SLIDES_LIMIT];
	int n_templates;
} Presentation;

Presentation* presentation_new();
Slide* presentation_add_slide(Presentation* presentation, char* parent);
Slide* presentation_add_template(Presentation* presentation, char* name, char* parent);
CommandText* slide_add_text_command(Slide* slide, char* text, CommandText* cmd_txt, int _continue);
CommandText* slide_add_template_command(Slide* slide, CommandText* cmd_txt, char* template_name);
CommandText* slide_add_templated_text(Slide* slide, char* template, char* text, CommandText* cmd_txt);
CommandImage* slide_add_image_command(Slide* slide, char* path);

#endif
