#ifndef PRESENTATION_H
#define PRESENTATION_H

// commands
typedef struct {
	char* text;
	int x, y, w, h;
	double size;
} CommandText;

typedef struct {
	char* path;
	int x, y, w, h;
	double scale;
} CommandImage;

typedef struct {
	char* path;
	enum { full, horizontal, vertical } anchor;
} CommandBackground;

typedef union {
	CommandText text;
	CommandImage image;
	CommandBackground background;
} CommandUnion;

typedef struct {
	enum { T_TEXT, T_IMAGE } type;
	CommandUnion command;
} Command;

// --

typedef struct {
	char* key;
	char* value;
} Parameter;

typedef struct {
	Command* commands[1024];
	int n_commands;
} Slide;

typedef struct {
	char* filename;
	Slide* slides[1024];
	int n_slides;
} Presentation;

Presentation* presentation_new();
Slide* presentation_add_slide(Presentation* presentation);
CommandText* slide_add_text_command(Slide* slide, char* text, CommandText* cmd_txt);
CommandImage* slide_add_image_command(Slide* slide, char* path);

#endif
