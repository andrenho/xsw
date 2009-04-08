#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#include "presentation.h"

char* sans = "sans";
char* serif = "serif";

Presentation* presentation_new()
{
	Presentation *p = malloc(sizeof(Presentation));
	p->filename = NULL;
	p->slides = NULL;
	p->templates = NULL;
#ifdef DEBUG
	printf("parser: new presentation.\n");
#endif
	return p;
}

Slide* pr_add_slide(Presentation* p, Slide* sl)
{
	if(sl->type == T_SLIDE)
		p->slides = append(p->slides, sl);
	else
		p->templates = append(p->templates, sl);

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

	return sl;
}
