%{
#include <stdio.h>
#include <stdlib.h>
#include "presentation.h"
#include "parser.h"

extern FILE *yyin;
static Presentation* pr;
static Slide* cr_slide;
static CommandText* cr_txt_cmd;

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

%token SLIDE COLON HIFEN ID TEXT X Y NUM

%%

slides:
      | slides slide;

slide: SLIDE COLON
     | SLIDE COLON { cr_slide = presentation_add_slide(pr); } commands;

commands:
	| commands command;

command: text_command;


/* 
 * Text command 
 */
text_command: HIFEN TEXT COLON ID { cr_txt_cmd = slide_add_text_command(cr_slide, $4); } text_parameters;

text_parameters:
	       | text_parameters text_parameter;

text_parameter:
	       | X COLON NUM { cr_txt_cmd->x = $3; }
	       | Y COLON NUM { cr_txt_cmd->y = $3; }
