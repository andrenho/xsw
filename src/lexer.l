%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
%}

%option nounput
%option noinput

%%

#.*\n			; // ignore comments
\/\*[.\n]*\*\/		;

slide			return SLIDE;
template		return TEMPLATE;
\-[\ ]*           	return HIFEN;

text            	return TEXT;
image			return IMAGE;
background		return BACKGROUND;

x			return X;
y			return Y;
w			return W;
h			return H;
size			return SIZE;
scale                   return SCALE;
font			return FONT;
style			return STYLE;
align			return ALIGN;
expand			return EXPAND;

horizontal		return HORIZONTAL;
right			return RIGHT;
italic			return ITALIC;

\".*\"			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return ID;
\'.*\'			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return ID;
[a-zA-Z][a-zA-Z0-9\.]*	yylval.cval = strdup(yytext); return ID;
[\-]?[0-9\.]*		yylval.dval = strtod(yytext, (char**)NULL); return NUM;

\:           		return COLON;
[\ \t\n]		; // ignore spaces

%%
