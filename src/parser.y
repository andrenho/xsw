%{
#include <stdio.h>
#include "presentation.h"
#include "parser.h"

extern FILE *yyin;

void yyerror(const char *s)
{
	fprintf(stderr, "error: %s\n", s);
	exit(1);
}

int yywrap()
{
	return 1;
}

int parser_parse(Presentation *pres, char *filename)
{
	yyin = fopen(filename, "r");
	yyparse();
	return 1;
}

%}

%token SLIDE COLON HIFEN ID TEXT

%%

slides:
      | slides slide;

slide: SLIDE COLON
     | SLIDE COLON commands;

commands:
	| commands command;

command: text_command;

text_command: HIFEN TEXT COLON ID { printf("Text command: %s\n", $4); }
