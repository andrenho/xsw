%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

%token SLIDE COLON HIFEN TEXT X Y W H IMAGE SIZE SCALE TEMPLATE BACKGROUND FONT
%token STYLE ITALIC ALIGN RIGHT EXPAND HORIZONTAL CENTER PLUS
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

template: TEMPLATE COLON ID { pr_add_slide(pr, template_new($3)); } commands
	| TEMPLATE COLON ID ID { pr_add_slide_from(pr, template_new($3), $4); } commands;

slides: slide
      | slides slide;

slide: SLIDE COLON { pr_add_slide(pr, slide_new()); } commands
     | SLIDE COLON ID { pr_add_slide_from(pr, slide_new(), $3); } commands;

commands: 
	| commands command;

command: text_command
       | image_command
       | background_command
       | template_command;

/* 
 * Text command 
 */
text_command: HIFEN TEXT COLON ID text_parameters
            | PLUS TEXT COLON ID text_parameters

text_parameters:
	       | text_parameters text_parameter;

text_parameter: X COLON NUM
	      | Y COLON NUM
              | SIZE COLON NUM
              | FONT COLON ID
              | STYLE COLON ITALIC
              | ALIGN COLON RIGHT
              | ALIGN COLON CENTER

/*
 * Image command
 */
image_command: HIFEN IMAGE COLON ID image_parameters;

image_parameters:
		| image_parameters image_parameter;

image_parameter: X COLON NUM
	       | Y COLON NUM
	       | W COLON NUM
	       | H COLON NUM
               | SCALE COLON NUM

/*
 * Template command
 */
template_command: HIFEN ID COLON text_parameters
		| HIFEN ID COLON ID text_parameters;

/*
 * Background command
 */
background_command: HIFEN BACKGROUND COLON ID background_parameters;

background_parameters:
		     | background_parameters background_parameter;

background_parameter: EXPAND COLON HORIZONTAL
                    | X COLON NUM 
	            | Y COLON NUM 

