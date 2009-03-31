#include <assert.h>
#include <stdlib.h>
#include "xslide.h"

#define HOR 8.1
#define VER 8.1

void slide_draw(cairo_t *cr, int w, int h, Presentation* p, int slide)
{
	int i;
	CommandText *cmd_txt;

	assert(slide < p->n_slides);

	// ratio
	float r;
	if((float)w / (float)h > (4/3))
		w = (float)h * (4/3);
	r = (float)w / 640;
	cairo_scale(cr, r, r);
	
	for(i=0; i<p->slides[slide]->n_commands; i++)
	{
		switch(p->slides[slide]->commands[i]->type)
		{
		case T_TEXT:
			{
				CommandText* cmd = &p->slides[slide]->commands[i]->command.text;

				if(cmd->y == -1) // default
				{
					if(cmd_txt)
						cmd->y = cmd_txt->y + cmd->size;
					else
						cmd->y = 10;
				}

				cairo_select_font_face(cr, "Sans", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
				cairo_set_font_size(cr, cmd->size * 4);
				cairo_move_to(cr, (float)cmd->x * HOR, (float)cmd->y * VER);
				cairo_text_path(cr, cmd->text);
				cairo_set_source_rgb(cr, 1, 1, 1);
				cairo_fill_preserve(cr);
				cairo_set_source_rgb(cr, 0, 0, 0);
				cairo_set_line_width(cr, 1.5);
				cairo_stroke(cr);

				cmd_txt = cmd;
			}
			break;
		case T_IMAGE:
			{
				cairo_surface_t* image;
				CommandImage* img = &p->slides[slide]->commands[i]->command.image;
				image = cairo_image_surface_create_from_png(img->path);

				if(img->scale == 1)
					cairo_set_source_surface(cr, image, img->x * HOR, img->y * VER);

				cairo_paint(cr);
			}
			break;
		default:
			abort();
		}
	}
}
