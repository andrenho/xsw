#include <stdlib.h>
#include <string.h>

#include <stdio.h>
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

CommandText* slide_add_text_command(Slide* slide, char* text, CommandText* cmd_txt)
{
	// get defaults
	int df_size, df_x, df_y;
	if(cmd_txt)
	{
		df_x = cmd_txt->x;
		df_y = -1;
		df_size = cmd_txt->size;
	}
	else
	{
		df_x = df_y = 10;
		df_size = 10;
	}

	// create command
	Command* cmd = malloc(sizeof(Command));
	slide->commands[slide->n_commands++] = cmd;

	cmd->type = T_TEXT;
	cmd->command.text.text = strdup(text);
	cmd->command.text.x = df_x;
	cmd->command.text.y = df_y;
	cmd->command.text.size = df_size;
#ifdef DEBUG
	printf("parser: new text command: %s.\n", text);
#endif
	return &cmd->command.text;
}

CommandImage* slide_add_image_command(Slide* slide, char* path)
{
	Command* cmd = malloc(sizeof(Command));
	slide->commands[slide->n_commands++] = cmd;

	cmd->type = T_IMAGE;
	cmd->command.image.path = strdup(path);
#ifdef DEBUG
	printf("parser: new image command: %s.\n", path);
#endif
	return &cmd->command.image;
}
