%{
#include <stdio.h>
#include "parser.h"
%}

%%

#.*\n			; // ignore comments
x			return X;
y			return Y;
w			return W;
h			return H;
size			return SIZE;
scale                   return SCALE;
slide			return SLIDE;
text            	return TEXT;
image			return IMAGE;
\".*\"			yytext[strlen(yytext)-1] = '\0'; yylval = (int)strdup(yytext+1); return ID;
\'.*\'			yytext[strlen(yytext)-1] = '\0'; yylval = (int)strdup(yytext+1); return ID;
[a-zA-Z][a-zA-Z0-9]*    yylval = (int)strdup(yytext); return ID;
[0-9]*			yylval = atoi(yytext); return NUM;
\-           		return HIFEN;
\:           		return COLON;
[\ \t\n]		; // ignore spaces

%%
