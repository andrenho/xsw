%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
\".*\"			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return ID;
\'.*\'			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return ID;
[a-zA-Z][a-zA-Z0-9]*    yylval.cval = strdup(yytext); return ID;
[0-9]*			yylval.ival = atoi(yytext); return NUM;
[0-9\.]*		{
				// printf("(%g) %d\n", atof(yytext), yyleng);
				double d = strtod(yytext, (char**)NULL);
				yylval.dval = d;
				return FLOAT;
			}
\-           		return HIFEN;
\:           		return COLON;
[\ \t\n]		; // ignore spaces

%%
