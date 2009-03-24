#ifndef PRESENTATION_H
#define PRESENTATION_H

typedef struct {
	char* key;
	char* value;
} Parameter;

typedef struct {
	char* id;
	Parameter* parameters[16];
	int n_parameters;
} Command;

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
Command* slide_add_command(Slide* slide);
Parameter* command_add_parameter(Command* command, char* key);

#endif
