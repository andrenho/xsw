#include <io.h>
#include "x2h_template.h"

static char* save_image(Slide* s)
{
	return "teste.png";
}

int x2h_template_generate(Presentation* p, char* tpl, PageType page)
{
	Slide *first = (Slide*)p->slides->data;
	Slide *lst = (Slide*)last(p->slides);

	mkdir(p->name);
	
	return 1;
}
