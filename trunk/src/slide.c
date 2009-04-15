#include <stdlib.h>
#include "slide.h"

Slide* slide_new()
{
	Slide* sl = malloc(sizeof(Slide));
	sl->commands = NULL;
	sl->id = NULL;
	sl->parent = NULL;
	sl->type = T_SLIDE;
	sl->bg_color[0] = sl->bg_gradient[0] = 
			sl->bg_color[1] = sl->bg_gradient[1] = 
			sl->bg_color[2] = sl->bg_gradient[2] = 0;
	return sl;
}

Slide* template_new(char* id)
{
	Slide* sl = malloc(sizeof(Slide));
	sl->commands = NULL;
	sl->id = id;
	sl->parent = NULL;
	sl->type = T_TEMPLATE;
	sl->bg_color[0] = sl->bg_gradient[0] = 
			sl->bg_color[1] = sl->bg_gradient[1] = 
			sl->bg_color[2] = sl->bg_gradient[2] = 0;
	return sl;
}

void* slide_add_command(Slide* slide, CommandType type, void* command)
{
	slide->commands = append_t(slide->commands, command, type);
	return command;
}

void* slide_add_custom_command(Slide* slide, char* id, char* text)
{
	CommandText *cmd, *cmd_new;

	// find original template
	if(!slide->parent)
	{
		fprintf(stderr, "Slide doesn't have a template for id %s\n.", id);
		exit(1);
	}

	List* cmds = slide->parent->commands;
	while(cmds)
	{
		if(cmds->type == T_TEXT)
		{
			cmd = (CommandText*)cmds->data;
			if(cmd->id)
				if(strcmp(cmd->id, id) == 0)
					goto found;
		}
		cmds = cmds->next;
	}

	fprintf(stderr, "Template %s not found.\n", id);
	exit(1);

found:
	cmd_new = cmd_txt_new_custom(text, cmd);
	slide->commands = append_t(slide->commands, cmd_new, T_TEXT);
	return (void*)cmd_new;
}
