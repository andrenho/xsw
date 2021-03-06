/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "presentation.h"

char* sans = "sans";
char* serif = "serif";

Presentation* presentation_new()
{
	Presentation *p = malloc(sizeof(Presentation));
	if (p == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	p->filename = NULL;
	p->path = NULL;
	p->slides = NULL;
	p->templates = NULL;
	p->image_path = NULL;
	p->name = "TODO"; // TODO
	return p;
}

Slide* pr_add_slide(Presentation* p, Slide* sl)
{
	if(sl->type == T_SLIDE)
		p->slides = ladd(p->slides, sl);
	else
		p->templates = ladd(p->templates, sl);

	return sl;
}

Slide* pr_add_slide_from(Presentation* p, Slide* sl, char* _template)
{
	// find template
	List* tpl = p->templates;
	int found = 0;
	while(tpl)
	{
		if(strcmp(((Slide*)tpl->data)->id, _template) == 0)
		{
			found = 1;
			break;
		}
		tpl = tpl->next;
	}
	if(!found)
	{
		fprintf(stderr, "Template %s not found.\n", _template);
		exit(1);
	}

	sl->parent = tpl->data;
	pr_add_slide(p, sl);

	// copy parent slide commands
	List* cmd = sl->parent->commands;
	while(cmd)
	{
		if(TYPE(cmd->data) == T_TEXT)
			if(!((CommandText*)cmd->data)->text)
				goto skip;
		sl->commands = ladd(sl->commands, cmd->data);
skip:
		cmd = cmd->next;
	}

	// background
	memcpy(sl->bg_color, sl->parent->bg_color, 3);
	memcpy(sl->bg_gradient, sl->parent->bg_gradient, 3);

	return sl;
}
