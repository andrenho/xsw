%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
%}

%option nounput

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
template		return TEMPLATE;
\".*\"			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return ID;
\'.*\'			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return ID;
[a-zA-Z][a-zA-Z0-9]*    yylval.cval = strdup(yytext); return ID;
[0-9\.]*		yylval.dval = strtod(yytext, (char**)NULL); return NUM;
\-           		return HIFEN;
\:           		return COLON;
[\ \t\n]		; // ignore spaces

%%
