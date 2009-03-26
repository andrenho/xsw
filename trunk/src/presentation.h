#ifndef PRESENTATION_H
#define PRESENTATION_H

// commands
typedef struct {
	char* text;
	int x, y, w, h;
} CommandText;

typedef struct {
	char* path;
	int x, y, w, h;
} CommandImage;

typedef struct {
	char* path;
	enum { full, horizontal, vertical, nw, n, ne, e, sw, s, se, w } anchor;
} CommandBackground;

typedef union {
	CommandText text;
	CommandImage image;
	CommandBackground background;
} CommandUnion;

typedef struct {
	enum { text, image, background } type;
	CommandUnion command;
} Command;

// --

typedef struct {
	char* key;
	char* value;
} Parameter;

typedef struct {
	char* id;
	Parameter* parameters[16];
	int n_parameters;
} UnparsedCommand;

typedef struct {
	Command* commands[1024];
	UnparsedCommand* unparsed_commands[1024];
	int n_commands;
} Slide;

typedef struct {
	char* filename;
	Slide* slides[1024];
	int n_slides;
} Presentation;

Presentation* presentation_new();
Slide* presentation_add_slide(Presentation* presentation);
UnparsedCommand* slide_add_unparsed_command(Slide* slide);
Parameter* command_add_parameter(UnparsedCommand* command, char* key);
int presentation_parse(Presentation* presentation);

#endif
