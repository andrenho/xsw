%{

#include <stdio.h>
#include <stdlib.h>

extern int line_no;

void yyerror(const char *s)
{
	fprintf(stderr, "xswpp: preprocessor error: %s in line %d\n", s, line_no);
	exit(1);
}

int yywrap()
{
	return 1;
}

int main()
{
	yyparse();
	return 0;
}

%}

%token PERCENT INCLUDE LINE ENTER
%union {
	char* c;
}
%token <c> STRING

%%

lines:
     | lines line

line: preprocess
    | LINE { printf("%s", yylval.c); }

preprocess: include
	  
include: PERCENT INCLUDE STRING ENTER { printf("--> %s\n", yylval.c); }

%%
