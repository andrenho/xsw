/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://www.gnu.org/licenses/gpl-3.0.txt/> */

#include <stdlib.h>
#include <string.h>
#include "cmd_text.h"
#include "slide.h"

CommandText* cmd_txt_new(char* text, CommandText* previous)
{
	CommandText* cmd_txt = malloc(sizeof(CommandText));
	cmd_txt->type = 1; //T_TEXT;
	if (cmd_txt == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}
	cmd_txt->id = NULL;
	cmd_txt->text = text;
	cmd_txt->x = DEFAULT_TXT_X;
	if(previous)
		cmd_txt->y = SET_ON_RUNTIME;
	else
		cmd_txt->y = DEFAULT_TXT_Y;
	cmd_txt->h = 0;
	cmd_txt->font = DEFAULT_FONT;
	cmd_txt->size = DEFAULT_SIZE;
	cmd_txt->style = DEFAULT_STYLE;
	cmd_txt->align = DEFAULT_ALIGN;
	cmd_txt->previous = previous;
	cmd_txt->color[0] = cmd_txt->color[1] = cmd_txt->color[2] = 0xff; // white
	cmd_txt->has_border = 1;
	cmd_txt->border[0] = cmd_txt->border[1] = cmd_txt->border[2] = 0x0; // black
	return cmd_txt;
}

CommandText* cmd_txt_new_plus(char* text, CommandText* previous)
{
	CommandText* cmd_txt = malloc(sizeof(CommandText));
	if (cmd_txt == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}

	// copy from previous
	if(previous)
		memcpy(cmd_txt, previous, sizeof(CommandText));
	cmd_txt->text = text;
	cmd_txt->y = SET_ON_RUNTIME;
	cmd_txt->previous = previous;
	
	return cmd_txt;
}

CommandText* cmd_txt_new_custom(char* text, CommandText* custom)
{
	CommandText* cmd_txt = malloc(sizeof(CommandText));
	if (cmd_txt == NULL) 
	{
		fprintf(stderr, "Not enough memory\n");
		exit(1);		
	}

	// copy from previous
	memcpy(cmd_txt, custom, sizeof(CommandText));
	cmd_txt->text = text;
	cmd_txt->previous = custom;
	
	return cmd_txt;
}

CommandText* cmd_txt_new_template(char* id)
{
	CommandText* cmd_txt = cmd_txt_new(NULL, NULL);
	cmd_txt->id = id;
	return cmd_txt;
}

