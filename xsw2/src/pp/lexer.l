%{

#include <string.h>
#include "parser.h"

int line_no = 1;

%}

%option nounput
%option noinput

%%

[ |\t]*\".*\"	{
	yylval.c = strdup(strchr(yytext, '"') + 1);
	yylval.c[strlen(yylval.c)-1] = '\0';
	return STRING;
}

[ |\t]*\'.*\'	{
	yylval.c = strdup(strchr(yytext, '\'') + 1);
	yylval.c[strlen(yylval.c)-1] = '\0';
	return STRING;
}

^[^%].*?\n	{
	line_no++; 
	yylval.c = (char*)strdup(yytext); 
	return LINE;
}

include		return INCLUDE;
^%		return PERCENT;
\n		return ENTER;

%%
