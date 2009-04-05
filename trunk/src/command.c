#include <assert.h>
#include "command.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_rotozoom.h"

void command_parse(Presenter* pr, Command* cmd)
{
	pr = pr; // avoid warnings

	if(cmd->dirty == 0)
		return;

	SDL_Surface* tmp;
	CommandImage* img;
	CommandText* txt;
	SDL_Color black = { 0, 0, 0, 0 };
	SDL_Color white = { 255, 255, 255, 0 };

	switch(cmd->type)
	{
	case T_TEXT:
		txt = &cmd->command.text;
#ifdef DEBUG
		printf("building: %s...", txt->text);
#endif
		TTF_Font* font;

		// load font - TODO slow, someday we'll not do this for every text block
		if(strcmp(txt->font, "sans") == 0)
			font = TTF_OpenFont(DATADIR "VeraBd.ttf", txt->size);
		else if(strcmp(txt->font, "serif") == 0)
			font = TTF_OpenFont(DATADIR "VeraSeBd.ttf", txt->size);
		else if(strcmp(txt->font, "mono") == 0)
			font = TTF_OpenFont(DATADIR "VeraMono.ttf", txt->size);
		else
		{
			fprintf(stderr, "warning: Font %s not found, defaulting to Sans.", txt->font);
			font = TTF_OpenFont(DATADIR "VeraBd.ttf", txt->size);
		}
		assert(txt->font);

		if(txt->italic)
			TTF_SetFontStyle(font, TTF_STYLE_ITALIC);

		txt->surface = TTF_RenderUTF8_Blended(font, txt->text, white);
		txt->surface_inv = TTF_RenderUTF8_Blended(font, txt->text, black);
#ifdef DEBUG
		printf("done!\n");
#endif
		break;


	case T_IMAGE:
		img = &cmd->command.image;
#ifdef DEBUG
		printf("building: %s...", img->path);
#endif
		tmp = IMG_Load(img->path);
		if(!tmp)
			fprintf(stderr, "Error loading image %s: %s.\n", img->path, IMG_GetError());
		
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
			if(img->expand_horiz)
			{
				w = (float)SCR_W / (float)tmp->w; // we'll value the width over the height
				h = ((float)tmp->h / (float)tmp->w * (float)SCR_W) / (float)tmp->h;
			}
			else
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
		break;

	default:
		abort();
	}
	cmd->dirty = 0;
}
