/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#ifndef SLIDE_H
#define SLIDE_H

#include "list.h"
#include "cmd_text.h"

#define T_TEXT  1
#define T_IMAGE 2
#define TYPE(var) ((char*)(var))[0]

typedef enum { T_SLIDE, T_TEMPLATE } SlideType;

/* A Slide structure can be either a slide or a template. A template will have
 * an ID, a slide won't. The parent will always be a template. */
typedef struct Slide {
	List* commands;
	char* id;
	unsigned char bg_color[3];
	unsigned char bg_gradient[3];
	struct Slide* parent;
	SlideType type;
	int dirty;
} Slide;

Slide* slide_new();
Slide* template_new(char *id);
void* slide_add_command(Slide* slide, void* command);
void* slide_add_custom_command(Slide* slide, char* id, char* text);

#endif
