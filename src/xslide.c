#include <assert.h>
#include "xslide.h"

void slide_draw(cairo_t *cr, int w, int h, Presentation* p, int slide)
{
	int i;

	assert(slide < p->n_slides);

	cairo_set_source_rgb(cr, 1, 1, 1);
	cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, 40.0);
	
	for(i=0; i<p->slides[slide]->n_commands; i++)
	{
		CommandText* cmd = p->slides[slide]->commands[i];
		cairo_move_to(cr, cmd->x, cmd->y);
		cairo_show_text(cr, cmd->text);
	}
}
