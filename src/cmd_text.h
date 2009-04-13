#ifndef CMD_TEXT_H
#define CMD_TEXT_H

#ifdef USE_SDL
#	include "SDL.h"
#endif

#define SET_ON_RUNTIME	-56734

#define DEFAULT_TXT_X 	4
#define DEFAULT_TXT_Y 	3
#define DEFAULT_FONT	"sans"
#define DEFAULT_SIZE	36
#define DEFAULT_STYLE	nostyle
#define DEFAULT_ALIGN	left

typedef enum { left, center, right } Alignment;
typedef enum { nostyle, italic } StyleType;

typedef struct CommandText {
	char* id;
	char* text;
	double x, y, h;
	char* font;
	double size;
	StyleType style;
	Alignment align;
	struct CommandText* previous;
#ifdef USE_SDL
	SDL_Surface* surface;
	SDL_Surface* surface_inv;
#endif
} CommandText;

CommandText* cmd_txt_new(char* text, CommandText* previous);
CommandText* cmd_txt_new_plus(char* text, CommandText* previous);
CommandText* cmd_txt_new_custom(char* text, CommandText* custom);
CommandText* cmd_txt_new_template(char* id);

#endif
