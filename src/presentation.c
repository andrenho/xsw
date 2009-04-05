#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "presentation.h"

const char* sans = "sans";
const char* serif = "serif";

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

static Slide* copy_from_parent(Presentation* p, Slide* s, char* parent)
{
	// do we have a parent?
	if(!parent)
		return NULL;

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
	{
		if(pnt->commands[i]->type == T_TEXT)
			if(pnt->commands[i]->command.text.text == NULL)
				continue;
		s->commands[s->n_commands++] = pnt->commands[i];
	}

	return pnt;
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
	s->parent = copy_from_parent(presentation, s, parent);

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
	s->name = strdup(name);
	presentation->templates[presentation->n_templates++] = s;
#ifdef DEBUG
	printf("parser: new slide.\n");
#endif
	s->parent = copy_from_parent(presentation, s, parent);

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
		df_x = df_y = 5;
		df_size = 36;
	}

	// create command
	Command* cmd = malloc(sizeof(Command));
	slide->commands[slide->n_commands++] = cmd;

	cmd->type = T_TEXT;
	cmd->dirty = 1;
	cmd->command.text.template_name = NULL;
	if(text)
		cmd->command.text.text = strdup(text);
	else
		cmd->command.text.text = NULL;
	cmd->command.text.x = df_x;
	cmd->command.text.y = df_y;
	cmd->command.text.size = df_size;
	cmd->command.text.font = sans;
	cmd->command.text.italic = 0;
	cmd->command.text.align_right = 0;
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

	CommandImage* img = &cmd->command.image;
	img->path = strdup(path);
	img->scale = 1;
	img->background = 0;
	img->x = 0;
	img->y = 0;
	img->expand_horiz = 0;
#ifdef DEBUG
	printf("parser: new image command: %s.\n", path);
#endif
	return &cmd->command.image;
}

CommandText* slide_add_template_command(Slide* slide, CommandText* cmd_txt, char* template_name)
{
	CommandText* txt = slide_add_text_command(slide, NULL, cmd_txt);
	txt->template_name = strdup(template_name);
	return txt;
}

CommandText* slide_add_templated_text(Slide* slide, char* template, char* text, CommandText* cmd_txt)
{
	// find origial
	if(!slide->parent)
	{
		fprintf(stderr, "Slide doesn't have a template.\n");
		exit(1);
	}

	int i;
	CommandText* txt_cmd = NULL;
	for(i=0; i<slide->parent->n_commands; i++)
		if(slide->parent->commands[i]->type == T_TEXT)
		{
			CommandText* txt = &slide->parent->commands[i]->command.text;
			if(txt->text == NULL)
				if(strcmp(txt->template_name, template) == 0)
					txt_cmd = txt;
		}
	if(!txt_cmd)
	{
		fprintf(stderr, "Template %s not found.\n", template);
		exit(1);
	}

	CommandText* txt = slide_add_text_command(slide, text, cmd_txt);
	memcpy(txt, txt_cmd, sizeof(CommandText));
	txt->text = strdup(text);
	return txt;
}
