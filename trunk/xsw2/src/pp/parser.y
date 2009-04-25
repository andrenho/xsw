%{

#include <stdio.h>
#include <stdlib.h>

extern FILE *yyin;

extern int line_no;
char* source;

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

line: LINE { printf("%s", yylval.c); }

%%
