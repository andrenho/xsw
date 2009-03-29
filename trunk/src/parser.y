%{
#include <stdio.h>
#include <stdlib.h>
#include "presentation.h"
#include "parser.h"

extern FILE *yyin;
static Presentation* pr;
static Slide* cr_slide;
static CommandText* cr_txt_cmd = 0x0;
static CommandImage* cr_img_cmd = 0x0;

void yyerror(const char *s)
{
	fprintf(stderr, "parser error: %s\n", s);
	exit(1);
}

int yywrap()
{
	return 1;
}

int parser_parse(Presentation *pres, char *filename)
{
	pr = pres;
	yyin = fopen(filename, "r");
	yyparse();
	return 1;
}

%}

%token SLIDE COLON HIFEN ID TEXT X Y W H NUM IMAGE SIZE SCALE

%%

slides:
      | slides slide;

slide: SLIDE COLON
     | SLIDE COLON { cr_slide = presentation_add_slide(pr); cr_txt_cmd = 0x0; } commands;

commands:
	| commands command;

command: text_command
       | image_command;


/* 
 * Text command 
 */
text_command: HIFEN TEXT COLON ID { cr_txt_cmd = slide_add_text_command(cr_slide, (unsigned char*)$4, cr_txt_cmd); } text_parameters;

text_parameters:
	       | text_parameters text_parameter;

text_parameter:
	       | X COLON NUM { cr_txt_cmd->x = $3; }
	       | Y COLON NUM { cr_txt_cmd->y = $3; }
               | SIZE COLON NUM { cr_txt_cmd->size = $3; }

/*
 * Image command
 */
image_command: HIFEN IMAGE COLON ID { cr_img_cmd = slide_add_image_command(cr_slide, (unsigned char*)$4); } image_parameters;

image_parameters:
		| image_parameters image_parameter;

image_parameter:
	       | X COLON NUM { cr_img_cmd->x = $3; }
	       | Y COLON NUM { cr_img_cmd->y = $3; }
	       | W COLON NUM { cr_img_cmd->w = $3; }
	       | H COLON NUM { cr_img_cmd->h = $3; }
               | SCALE COLON NUM { cr_img_cmd->scale = $3; }
