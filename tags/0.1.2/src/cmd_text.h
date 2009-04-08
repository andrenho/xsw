#ifndef CMD_TEXT_H
#define CMD_TEXT_H

#define DEFAULT_X 	4
#define DEFAULT_Y 	3
#define DEFAULT_FONT	"sans"
#define DEFAULT_SIZE	36
#define DEFAULT_ITALIC	0
#define DEFAULT_ALIGN	center

typedef struct CommandText {
	char* id;
	char* text;
	double x, y, h;
	char* font;
	double size;
	int italic;
	enum { left, center, right } align;
	int dirty;
	struct CommandText* previous;
#ifdef USE_SDL
	SDL_Surface* surface;
	SDL_Surface* surface_inv;
#endif
} CommandText;

CommandText* cmd_txt_new(char* id, char* text);
CommandText* cmd_txt_new_plus(char* id, char* text, CommandText* previous);

#endif
