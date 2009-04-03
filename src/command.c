#include "command.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "SDL_rotozoom.h"

void command_parse(Presenter* pr, Command* cmd)
{
	SDL_Surface* tmp;
	CommandImage* img;
	CommandText* txt;
	SDL_Color black = { 0, 0, 0, 0 };

	switch(cmd->type)
	{
	case T_TEXT:
		txt = &cmd->command.text;
		cmd->surface = TTF_RenderUTF8_Blended(pr->font, txt->text, black);
		break;

	case T_IMAGE:
		img = &cmd->command.image;
		tmp = IMG_Load(img->path);
		if(!tmp)
			fprintf(stderr, "Error loading image %s: %s.\n", img->path, IMG_GetError());
		
		if(img->scale == 1)
			cmd->surface = tmp;
		else
		{
			cmd->surface =zoomSurface(tmp, img->scale, img->scale, 1);
			SDL_FreeSurface(tmp);
		}
		break;

	default:
		abort();
	}
	cmd->dirty = 0;
}
