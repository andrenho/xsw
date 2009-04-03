#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "presentation.h"

Presentation* presentation_new()
{
	Presentation *p = malloc(sizeof(Presentation));
	p->n_slides = 0;
	p->n_templates = 0;
#ifdef DEBUG
	printf("parser: new presentation.\n");
#endif
	return p;
}

static void copy_from_parent(Presentation* p, Slide* s, char* parent)
{
	// do we have a parent?
	if(!parent)
		return;

	// who is this parent?
	int i;
	Slide* pnt = NULL;
	for(i=0; i<p->n_templates; i++)
		if(strcmp(p->templates[i]->name, parent) == 0)
		{
			pnt = p->templates[i];
			break;
		}
	
	if(!pnt)
	{
		fprintf(stderr, "Invalid template: %s.\n", parent);
		exit(1);
	}
	
	// import commands from parent
	for(i=0; i<pnt->n_commands; i++)
		s->commands[s->n_commands++] = pnt->commands[i];
}

Slide* presentation_add_slide(Presentation* presentation, char* parent)
{
	if(presentation->n_slides == SLIDES_LIMIT-1)
	{
		fprintf(stderr, "There's a fixed limit of %d slides in a presentation.\n", SLIDES_LIMIT);
		exit(1);
	}

	Slide* s = malloc(sizeof(Slide));
	s->n_commands = 0;
	presentation->slides[presentation->n_slides++] = s;
#ifdef DEBUG
	printf("parser: new slide.\n");
#endif
	copy_from_parent(presentation, s, parent);

	return s;
}

Slide* presentation_add_template(Presentation* presentation, char* name, char* parent)
{
	if(presentation->n_templates == SLIDES_LIMIT-1)
	{
		fprintf(stderr, "There's a fixed limit of %d templates in a presentation.\n", SLIDES_LIMIT);
		exit(1);
	}

	Slide* s = malloc(sizeof(Slide));
	s->n_commands = 0;
	s->name = name;
	presentation->templates[presentation->n_templates++] = s;
#ifdef DEBUG
	printf("parser: new slide.\n");
#endif
	copy_from_parent(presentation, s, parent);

	return s;	
}

CommandText* slide_add_text_command(Slide* slide, char* text, CommandText* cmd_txt)
{
	if(slide->n_commands == COMMANDS_LIMIT-1)
	{
		fprintf(stderr, "There's a fixed limit of %d commands in a slide.\n", COMMANDS_LIMIT);
		exit(1);
	}

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
	cmd->dirty = 1;
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
	cmd->dirty = 1;
	cmd->command.image.path = strdup(path);
#ifdef DEBUG
	printf("parser: new image command: %s.\n", path);
#endif
	return &cmd->command.image;
}
