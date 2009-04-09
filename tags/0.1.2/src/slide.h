#ifndef SLIDE_H
#define SLIDE_H

#include "list.h"

typedef enum { T_TEXT, T_IMAGE } CommandType;
typedef enum { T_SLIDE, T_TEMPLATE } SlideType;

/* A Slide structure can be either a slide or a template. A template will have
 * an ID, a slide won't. The parent will always be a template. */
typedef struct Slide {
	List* commands;
	char* id;
	struct Slide* parent;
	SlideType type;
} Slide;

Slide* slide_new();
Slide* template_new(char *id);
void* slide_add_command(Slide* slide, CommandType type, void* command);

#endif
