/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <stdlib.h>
#include "slide.h"

Slide* slide_new()
{
	Slide* sl = malloc(sizeof(Slide));
	if (sl == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	sl->commands = NULL;
	sl->id = NULL;
	sl->parent = NULL;
	sl->type = T_SLIDE;
	sl->bg_color[0] = sl->bg_gradient[0] = 
			sl->bg_color[1] = sl->bg_gradient[1] = 
			sl->bg_color[2] = sl->bg_gradient[2] = 0;
	sl->dirty = 1;
	return sl;
}

Slide* template_new(char* id)
{
	Slide* sl = malloc(sizeof(Slide));
	if (sl == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	sl->commands = NULL;
	sl->id = id;
	sl->parent = NULL;
	sl->type = T_TEMPLATE;
	sl->bg_color[0] = sl->bg_gradient[0] = 
			sl->bg_color[1] = sl->bg_gradient[1] = 
			sl->bg_color[2] = sl->bg_gradient[2] = 0;
	return sl;
}

void* slide_add_command(Slide* slide, void* command)
{
	slide->commands = ladd(slide->commands, command);
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
		if(TYPE(cmds->data) == T_TEXT)
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
	slide->commands = ladd(slide->commands, cmd_new);
	return (void*)cmd_new;
}
