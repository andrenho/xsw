#include <stdlib.h>
#include <string.h>
#include "cmd_text.h"

CommandText* cmd_txt_new(char* id, char* text, CommandText* previous)
{
	CommandText* cmd_txt = malloc(sizeof(CommandText));
	cmd_txt->id = id;
	cmd_txt->text = text;
	cmd_txt->x = DEFAULT_X;
	cmd_txt->y = DEFAULT_Y;
	cmd_txt->h = 0;
	cmd_txt->font = DEFAULT_FONT;
	cmd_txt->size = DEFAULT_SIZE;
	cmd_txt->italic = DEFAULT_ITALIC;
	cmd_txt->align = DEFAULT_ALIGN;
	cmd_txt->dirty = 1;
	cmd_txt->previous = previous;
	return cmd_txt;
}

CommandText* cmd_txt_new_plus(char* id, char* text, CommandText* previous)
{
	CommandText* cmd_txt = malloc(sizeof(CommandText));

	// copy from previous
	if(previous)
		memcpy(cmd_txt, previous, sizeof(CommandText));
	cmd_txt->previous = previous;
	
	return cmd_txt;
}
