#include <stdlib.h>
#include "slide.h"

Slide* slide_new()
{
	Slide* sl = malloc(sizeof(Slide));
	sl->commands = NULL;
	sl->id = NULL;
	sl->parent = NULL;
	sl->type = T_SLIDE;
	return sl;
}

Slide* template_new(char* id)
{
	Slide* sl = malloc(sizeof(Slide));
	sl->commands = NULL;
	sl->id = id;
	sl->parent = NULL;
	sl->type = T_TEMPLATE;
	return sl;
}

void* slide_add_command(Slide* slide, enum CommandType type, void* command)
{
	slide->commands = append(slide->commands, command);
	return command;
}
