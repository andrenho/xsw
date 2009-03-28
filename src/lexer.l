%{
#include <stdio.h>
#include "parser.h"
%}

%%

slide		return SLIDE;
text            return TEXT;
[a-zA-Z]*    	yylval = strdup(yytext); return ID;
\-           	return HIFEN;
\:           	return COLON;
[\ \t]		; // ignore spaces

%%
