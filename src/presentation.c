#include <stdlib.h>
#include <string.h>

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

UnparsedCommand* slide_add_unparsed_command(Slide* slide)
{
	UnparsedCommand* c = malloc(sizeof(UnparsedCommand));
	c->n_parameters = 0;
	c->id = '\0';
	slide->unparsed_commands[slide->n_commands++] = c;
#ifdef DEBUG
	printf("New command.\n");
#endif
	return c;
}

Parameter* command_add_parameter(UnparsedCommand* command, char* key)
{
	// TODO
	Parameter* p = malloc(sizeof(Parameter));
	if(key)
	{
		p->key = (char*)malloc(strlen(key) + 1);
		strcpy(p->key, key);
		command->parameters[command->n_parameters++] = p;
	#ifdef DEBUG
		printf("New parameter: %s.\n", key);
	#endif
	}
	return p;
}

//
// parsing commands
//
static void slide_parse_commands(Slide* slide)
{
	int i;
	for(i=0; i<slide->n_commands; i++)
	{
		
	}
}

void presentation_parse(Presentation* presentation)
{
	int i;
	for(i=0; i<presentation->n_slides; i++)
		slide_parse_commands(presentation->slides[i]);	
}
