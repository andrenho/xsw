%{

#include <string.h>
#include "parser.h"
#include "../common/list.h"

int line_no = 1;
extern List* l;

%}

%option nounput
%option noinput
%option noyywrap
%option warn

%x incl
%x def

%%

^[^%].*?	yylval.c = strdup(yytext); return LINE;
\n		ECHO; line_no++;

^%include	BEGIN(incl);
<incl>[ \t]*	/* eat the whitespace */
<incl>\".*\"|\'.*\'	{
	yytext[strlen(yytext)-1] = '\0';
	yyin = fopen(&yytext[1], "r");
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

^%define[ \t]	BEGIN(def); return DEFINE;
<def>[ \t]	;
<def>.*		yylval.c = strdup(yytext); return DEF_ID;
<def>\n		BEGIN(INITIAL);

%%
