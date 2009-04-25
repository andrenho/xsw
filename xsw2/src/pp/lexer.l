%{

#include <string.h>
#include "parser.h"

int line_no = 1;

%}

%option nounput
%option noinput

%x incl

%%

^%include	BEGIN(incl);
^[^%].*?\n	yylval.c = strdup(yytext); return LINE;

<incl>[ \t]*	/* eat the whitespace */
<incl>[^ \t\n]+	{
	yyin = fopen(yytext, "r");
	if(!yyin)
	{
		fprintf(stderr, "File %s not found.\n", yytext);
		exit(1);
	}
	
	yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

	BEGIN(INITIAL);
}

<<EOF>> {
	yypop_buffer_state();
	if(!YY_CURRENT_BUFFER)
		yyterminate();
}

%%
