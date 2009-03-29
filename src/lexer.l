%{
#include <stdio.h>
#include "parser.h"
%}

%%

x			return X;
y			return Y;
slide			return SLIDE;
text            	return TEXT;
\".*\"			yylval = (int)strdup(yytext); return ID;
[a-zA-Z][a-zA-Z0-9]*    yylval = (int)strdup(yytext); return ID;
[0-9]*			yylval = atoi(yytext); return NUM;
\-           		return HIFEN;
\:           		return COLON;
[\ \t\n]		; // ignore spaces

%%
