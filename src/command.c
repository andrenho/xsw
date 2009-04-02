#include "command.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

void command_parse(Command* cmd)
{
	CommandImage* img;
	CommandText* txt;

	switch(cmd->type)
	{
	case T_TEXT:
		break;

	case T_IMAGE:
		img = &cmd->command.image;
		cmd->surface = IMG_Load(img->path);
		if(!cmd->surface)
			fprintf(stderr, "Error loading image %s: %s.\n", img->path, IMG_GetError());
		break;

	default:
		abort();
	}
	cmd->dirty = 0;
}
