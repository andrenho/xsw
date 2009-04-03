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

extern int yylex(void);
int yyparse(void);

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

%token SLIDE COLON HIFEN TEXT X Y W H IMAGE SIZE SCALE TEMPLATE
%token <dval> NUM
%token <cval> ID

%union
{
	double dval;
	char* cval;
	int ival;
}

%%

presentation: templates slides
	    | slides;

templates: template
	 | templates template;

template: TEMPLATE COLON ID { cr_slide = presentation_add_template(pr, $3, NULL); cr_txt_cmd = 0x0; } commands
	| TEMPLATE COLON ID ID { cr_slide = presentation_add_template(pr, $3, $4); cr_txt_cmd = 0x0; } commands;

slides: slide
      | slides slide;

slide: SLIDE COLON { cr_slide = presentation_add_slide(pr, NULL); cr_txt_cmd = 0x0; }
     | SLIDE COLON { cr_slide = presentation_add_slide(pr, NULL); cr_txt_cmd = 0x0; } commands
     | SLIDE COLON ID { cr_slide = presentation_add_slide(pr, $3); cr_txt_cmd = 0x0; }
     | SLIDE COLON ID { cr_slide = presentation_add_slide(pr, $3); cr_txt_cmd = 0x0; } commands;

commands: command
	| commands command;

command: text_command
       | image_command
       | template_command;

/* 
 * Text command 
 */
text_command: HIFEN TEXT COLON ID { cr_txt_cmd = slide_add_text_command(cr_slide, $4, cr_txt_cmd); } text_parameters;

text_parameters:
	       | text_parameters text_parameter;

text_parameter: X COLON NUM { cr_txt_cmd->x = $3; }
	      | Y COLON NUM { cr_txt_cmd->y = $3; }
              | SIZE COLON NUM { cr_txt_cmd->size = $3; }

/*
 * Image command
 */
image_command: HIFEN IMAGE COLON ID { cr_img_cmd = slide_add_image_command(cr_slide, $4); } image_parameters;

image_parameters:
		| image_parameters image_parameter;

image_parameter: X COLON NUM { cr_img_cmd->x = $3; }
	       | Y COLON NUM { cr_img_cmd->y = $3; }
	       | W COLON NUM { cr_img_cmd->w = $3; }
	       | H COLON NUM { cr_img_cmd->h = $3; }
               | SCALE COLON NUM { cr_img_cmd->scale = $3; }

/*
 * Template command
 */
template_command: HIFEN ID COLON text_parameters
		| HIFEN ID COLON ID;
