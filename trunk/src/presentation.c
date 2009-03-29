#include <stdlib.h>
#include <string.h>

#include "presentation.h"

Presentation* presentation_new()
{
	Presentation *p = malloc(sizeof(Presentation));
	p->n_slides = 0;
#ifdef DEBUG
	printf("parser: new presentation.\n");
#endif
	return p;
}

Slide* presentation_add_slide(Presentation* presentation)
{
	Slide* s = malloc(sizeof(Slide));
	s->n_commands = 0;
	presentation->slides[presentation->n_slides++] = s;
#ifdef DEBUG
	printf("parser: new slide.\n");
#endif
	return s;
}

CommandText* slide_add_text_command(Slide* slide, char* text)
{
	CommandText* ct = malloc(sizeof(Command));
	slide->commands[slide->n_commands++] = ct;
	ct->text = strdup(text);
#ifdef DEBUG
	printf("parser: new text command: %s.\n", ct->text);
#endif
	return ct;
}
