#include "command.h"
#include "SDL_image.h"

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
		img->surface = IMG_Load(img->path);
		break;

	default:
		abort();
	}
	cmd->dirty = 0;
}
