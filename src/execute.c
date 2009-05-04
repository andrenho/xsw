/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <assert.h>
#include <stdlib.h>
#include "execute.h"
#include "cmd_img.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_rotozoom.h"

static TTF_Font* load_font(char* name, int size)
{
	char path[1024];
	sprintf(path, "/usr/share/fonts/TTF/%s", name);
	TTF_Font* font = TTF_OpenFont(path, size);
	if(!font)
	{
		sprintf(path, "%s/%s", DATADIR, name);
		font = TTF_OpenFont(path, size);
	}
	return font;
}

void execute_parse(Presenter* pr, void* cmd, CommandType type)
{
	SDL_Surface* tmp;
	CommandImage* img;
	CommandText* txt;

	switch(type)
	{
	case T_TEXT:
		txt = (CommandText*)cmd;
		TTF_Font* font;
		SDL_Color color = { txt->color[0], txt->color[1], txt->color[2], 0 };

		// load font - TOD slow, someday we'll not do this for every text block
		if(strcmp(txt->font, "sans") == 0)
			font = load_font("VeraBd.ttf", txt->size);
		else if(strcmp(txt->font, "serif") == 0)
			font = load_font("VeraSeBd.ttf", txt->size);
		else if(strcmp(txt->font, "mono") == 0)
			font = load_font("VeraMono.ttf", txt->size);
		else
		{
			fprintf(stderr, "warning: Font %s not found, defaulting to Sans.", txt->font);
			font = TTF_OpenFont(DATADIR "VeraBd.ttf", txt->size);
		}
		if(!font)
		{
			fprintf(stderr, "Default font %s could not be found. Are you sure you typed 'make install' after compiling xsd?", DATADIR "VeraBd.ttf");
			exit(1);
		}

		if(txt->style == italic)
			TTF_SetFontStyle(font, TTF_STYLE_ITALIC);

		txt->surface = TTF_RenderUTF8_Blended(font, txt->text, color);
		if(txt->h == 0)
			txt->h = (double)TTF_FontLineSkip(font) / (double)SCR_W * 100;

		if(txt->has_border)
		{
			SDL_Color border = { txt->border[0], txt->border[1], txt->border[2], 0 };
			txt->surface_inv = TTF_RenderUTF8_Blended(font, txt->text, border);
		}

		/* If the text is empty, then the surface generated is NULL.
		 * The user might want to use an empty text to show a empty
		 * line, so we'll create a transparent rectangle with the 
		 * text height. */
		if(!txt->surface)
		{
			txt->surface = SDL_CreateRGBSurface(SDL_SWSURFACE|SDL_SRCCOLORKEY, 1, txt->h, 0, 0, 0, 0, 0);
			txt->surface_inv = txt->surface;
		}
		assert(txt->surface);
		TTF_CloseFont(font);

		break;

	case T_IMAGE:
		img = (CommandImage*)cmd;
#ifdef DEBUG
		printf("Preloading %s...", img->path);
#endif
		char buf[512];

		tmp = NULL;

		// if image_path is set
		if(pr->p->image_path)
		{
			// get image path
			if(pr->p->image_path[0] == '/')
				sprintf(buf, "%s/%s", pr->p->image_path, img->path);
			else if(pr->p->image_path[0] == '~')
				sprintf(buf, "%s/%s/%s", getenv("HOME"), &pr->p->image_path[1], img->path);
			else
				sprintf(buf, "%s/%s/%s", pr->p->path, pr->p->image_path, img->path);
			tmp = IMG_Load(buf);
		}
		
		// image not found, of no image_path - search current directory
		if(!tmp)
		{
			sprintf(buf, "%s/%s", pr->p->path, img->path);
			tmp = IMG_Load(buf);
		}

		// image still not found
		if(!tmp)
		{
			fprintf(stderr, "Error loading image %s: %s.\n", img->path, IMG_GetError());
			exit(1);
		}
		
		if(!img->background)
		{
			if(img->scale == 1)
				img->surface = tmp;
			else
			{
				img->surface = zoomSurface(tmp, img->scale, img->scale, 1);
				SDL_FreeSurface(tmp);
			}
		}
		else
		{
			float w, h;
			if(img->expand == horizontal)
			{
				w = (float)SCR_W / (float)tmp->w; // we'll value the width over the height
				h = ((float)tmp->h / (float)tmp->w * (float)SCR_W) / (float)tmp->h;
			}
			else // vertical
			{
				h = (float)SCR_H / (float)tmp->h; // we'll value the height over the width
				w = ((float)tmp->w / (float)tmp->h * (float)SCR_H) / (float)tmp->w;
			}
			if(h != 1 || w != 1)
			{
				img->surface = zoomSurface(tmp, w, h, 1);
				SDL_FreeSurface(tmp);
			}
			else
				img->surface = tmp;
		}
#ifdef DEBUG
		printf("done!\n");
#endif
		assert(img->surface);
		break;
	default:
		abort();
	}
	
}
