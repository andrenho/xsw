%{
/* Source file covered by the GNU Public License v3 
 * See LICENSE file or <http://gplv3.fsf.org/> */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "parser.h"
#include "cmd_text.h"
#include "cmd_img.h"
#include "color.h"

int line_no = 1;

%}

%option nounput
%option noinput

%%

#.*\n			line_no++; // ignore comments

slide			return SLIDE;
template		return TEMPLATE;
\-[\ ]*           	return HIFEN;
\+[\ ]*			return PLUS;

text            	return TEXT;
image|img		return IMAGE;
background|bg		return BACKGROUND;

image_path		return IMAGE_PATH;
x			return X;
y			return Y;
h			return H;
w			return W;
size			return SIZE;
scale                   return SCALE;
font			return FONT;
style			return STYLE;
align			return ALIGN;
expand			return EXPAND;
gradient		return GRADIENT;
color			return COLOR_PAR;
border			return BORDER;

none			return NONE;

horizontal|vertical	{
				if(strcmp(yytext, "horizontal") == 0)
					yylval.ival = horizontal;
				else if(strcmp(yytext, "vertical") == 0)
					yylval.ival = vertical;
				return EXPAND_TYPE;
			}

left|center|right	{
				if(strcmp(yytext, "left") == 0)
					yylval.ival = left;
				else if(strcmp(yytext, "center") == 0)
					yylval.ival = center;
				else if(strcmp(yytext, "right") == 0)
					yylval.ival = right;
				return ALIGN_TYPE;
			}

nostyle|italic		{
				if(strcmp(yytext, "italic") == 0)
					yylval.ival = italic;
				else if(strcmp(yytext, "nostyle") == 0)
					yylval.ival = nostyle;
				return STYLE_TYPE;
			}

\$[0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f][0-9A-Fa-f] {
				int i, j;
				yylval.cval = malloc(3);
				for(i=1, j=0; i<=6; i+=2, j++)
				{
					char s[3];
					memcpy(s, &yytext[i], 2);
					s[2] = '\0';
					yylval.cval[j] = (unsigned char)strtol(s, NULL, 16);
				}
				return COLOR;
			}


\".*\"			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return STRING;
\'.*\'			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return STRING;

[a-zA-Z][a-zA-Z0-9\.]*	{
				int i = 0;
				yylval.cval = strdup(yytext);
				while(yylval.cval[i])
				{
					yylval.cval[i] = tolower(yylval.cval[i]);
					i++;
				}
				return ID;
			}

[\-]?[0-9]*[\.]?[0-9]*	yylval.dval = strtod(yytext, (char**)NULL); return NUM;

\:           		return COLON;
[\ \t]			; // ignore spaces
\n			line_no++;

%%
