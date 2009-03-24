#include <stdlib.h>

#include "presentation.h"

Presentation* presentation_new()
{
	Presentation *p = malloc(sizeof(Presentation));
	p->n_slides = 0;
#ifdef DEBUG
	printf("New presentation.\n");
#endif
	return p;
}

Slide* presentation_add_slide(Presentation* presentation)
{
	Slide* s = malloc(sizeof(Slide));
	s->n_commands = 0;
	presentation->slides[presentation->n_slides++] = s;
#ifdef DEBUG
	printf("New slide.\n");
#endif
	return s;
}

Command* slide_add_command(Slide* slide)
{
	Command* c = malloc(sizeof(Command));
	c->n_parameters = 0;
	c->id = '\0';
	slide->commands[slide->n_commands++] = c;
#ifdef DEBUG
	printf("New command.\n");
#endif
	return c;
}

Parameter* command_add_parameter(Command* command, char* key)
{
	// TODO
	Parameter* p = malloc(sizeof(Parameter));
	p->key = (char*)malloc(strlen(key) + 1);
	strcpy(p->key, key);
	command->parameters[command->n_parameters++] = p;
#ifdef DEBUG
	printf("New parameter: %s.\n", key);
#endif
	return p;
}
