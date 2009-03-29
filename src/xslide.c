#include <assert.h>
#include <stdlib.h>
#include "xslide.h"

void slide_draw(cairo_t *cr, int w, int h, Presentation* p, int slide)
{
	int i;

	assert(slide < p->n_slides);

	// ratio
	float r;
	if((float)w / (float)h > (4/3))
		w = (float)h * (4/3);
	r = (float)w / 100;

	
	for(i=0; i<p->slides[slide]->n_commands; i++)
	{
		switch(p->slides[slide]->commands[i]->type)
		{
		case T_TEXT:
			{
				CommandText* cmd = &p->slides[slide]->commands[i]->command.text;
				cairo_set_source_rgb(cr, 1, 1, 1);
				cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
				cairo_set_font_size(cr, 10.0 * r);
				cairo_move_to(cr, cmd->x * r, cmd->y * r);
				cairo_show_text(cr, cmd->text);
			}
			break;
		case T_IMAGE:
			{
				cairo_surface_t* image;
				CommandImage* img = &p->slides[slide]->commands[i]->command.image;
				image = cairo_image_surface_create_from_png(img->path);
				cairo_set_source_surface(cr, image, 10, 10);
				cairo_paint(cr);
			}
			break;
		default:
			abort();
		}
	}
}
