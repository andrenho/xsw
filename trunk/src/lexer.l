%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.h"
#include "cmd_text.h"
#include "cmd_img.h"

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
size			return SIZE;
scale                   return SCALE;
font			return FONT;
style			return STYLE;
align			return ALIGN;
expand			return EXPAND;
gradient		return GRADIENT;
color			return COLOR_PAR;

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

snow			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=250; yylval.cval[2]=250; return COLOR; }
GhostWhite		{ yylval.cval = malloc(3); yylval.cval[0]=248; yylval.cval[1]=248; yylval.cval[2]=255; return COLOR; }
WhiteSmoke		{ yylval.cval = malloc(3); yylval.cval[0]=245; yylval.cval[1]=245; yylval.cval[2]=245; return COLOR; }
gainsboro		{ yylval.cval = malloc(3); yylval.cval[0]=220; yylval.cval[1]=220; yylval.cval[2]=220; return COLOR; }
FloralWhite		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=250; yylval.cval[2]=240; return COLOR; }
OldLace			{ yylval.cval = malloc(3); yylval.cval[0]=253; yylval.cval[1]=245; yylval.cval[2]=230; return COLOR; }
linen			{ yylval.cval = malloc(3); yylval.cval[0]=250; yylval.cval[1]=240; yylval.cval[2]=230; return COLOR; }
AntiqueWhite		{ yylval.cval = malloc(3); yylval.cval[0]=250; yylval.cval[1]=235; yylval.cval[2]=215; return COLOR; }
PapayaWhip		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=239; yylval.cval[2]=213; return COLOR; }
BlanchedAlmond		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=235; yylval.cval[2]=205; return COLOR; }
bisque			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=228; yylval.cval[2]=196; return COLOR; }
PeachPuff		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=218; yylval.cval[2]=185; return COLOR; }
NavajoWhite		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=222; yylval.cval[2]=173; return COLOR; }
moccasin		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=228; yylval.cval[2]=181; return COLOR; }
cornsilk		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=248; yylval.cval[2]=220; return COLOR; }
ivory			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=240; return COLOR; }
LemonChiffon		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=250; yylval.cval[2]=205; return COLOR; }
seashell		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=245; yylval.cval[2]=238; return COLOR; }
honeydew		{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=255; yylval.cval[2]=240; return COLOR; }
MintCream		{ yylval.cval = malloc(3); yylval.cval[0]=245; yylval.cval[1]=255; yylval.cval[2]=250; return COLOR; }
azure			{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
AliceBlue		{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=248; yylval.cval[2]=255; return COLOR; }
lavender		{ yylval.cval = malloc(3); yylval.cval[0]=230; yylval.cval[1]=230; yylval.cval[2]=250; return COLOR; }
LavenderBlush		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=240; yylval.cval[2]=245; return COLOR; }
MistyRose		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=228; yylval.cval[2]=225; return COLOR; }
white			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
black			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
DarkSlateGray		{ yylval.cval = malloc(3); yylval.cval[0]=47; yylval.cval[1]=79; yylval.cval[2]=79; return COLOR; }
DarkSlateGrey		{ yylval.cval = malloc(3); yylval.cval[0]=47; yylval.cval[1]=79; yylval.cval[2]=79; return COLOR; }
DimGray			{ yylval.cval = malloc(3); yylval.cval[0]=105; yylval.cval[1]=105; yylval.cval[2]=105; return COLOR; }
DimGrey			{ yylval.cval = malloc(3); yylval.cval[0]=105; yylval.cval[1]=105; yylval.cval[2]=105; return COLOR; }
SlateGray		{ yylval.cval = malloc(3); yylval.cval[0]=112; yylval.cval[1]=128; yylval.cval[2]=144; return COLOR; }
SlateGrey		{ yylval.cval = malloc(3); yylval.cval[0]=112; yylval.cval[1]=128; yylval.cval[2]=144; return COLOR; }
LightSlateGray		{ yylval.cval = malloc(3); yylval.cval[0]=119; yylval.cval[1]=136; yylval.cval[2]=153; return COLOR; }
LightSlateGrey		{ yylval.cval = malloc(3); yylval.cval[0]=119; yylval.cval[1]=136; yylval.cval[2]=153; return COLOR; }
gray			{ yylval.cval = malloc(3); yylval.cval[0]=190; yylval.cval[1]=190; yylval.cval[2]=190; return COLOR; }
grey			{ yylval.cval = malloc(3); yylval.cval[0]=190; yylval.cval[1]=190; yylval.cval[2]=190; return COLOR; }
LightGrey		{ yylval.cval = malloc(3); yylval.cval[0]=211; yylval.cval[1]=211; yylval.cval[2]=211; return COLOR; }
LightGray		{ yylval.cval = malloc(3); yylval.cval[0]=211; yylval.cval[1]=211; yylval.cval[2]=211; return COLOR; }
MidnightBlue		{ yylval.cval = malloc(3); yylval.cval[0]=25; yylval.cval[1]=25; yylval.cval[2]=112; return COLOR; }
navy			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=128; return COLOR; }
NavyBlue		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=128; return COLOR; }
CornflowerBlue		{ yylval.cval = malloc(3); yylval.cval[0]=100; yylval.cval[1]=149; yylval.cval[2]=237; return COLOR; }
DarkSlateBlue		{ yylval.cval = malloc(3); yylval.cval[0]=72; yylval.cval[1]=61; yylval.cval[2]=139; return COLOR; }
SlateBlue		{ yylval.cval = malloc(3); yylval.cval[0]=106; yylval.cval[1]=90; yylval.cval[2]=205; return COLOR; }
MediumSlateBlue		{ yylval.cval = malloc(3); yylval.cval[0]=123; yylval.cval[1]=104; yylval.cval[2]=238; return COLOR; }
LightSlateBlue		{ yylval.cval = malloc(3); yylval.cval[0]=132; yylval.cval[1]=112; yylval.cval[2]=255; return COLOR; }
MediumBlue		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=205; return COLOR; }
RoyalBlue		{ yylval.cval = malloc(3); yylval.cval[0]=65; yylval.cval[1]=105; yylval.cval[2]=225; return COLOR; }
blue			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=255; return COLOR; }
DodgerBlue		{ yylval.cval = malloc(3); yylval.cval[0]=30; yylval.cval[1]=144; yylval.cval[2]=255; return COLOR; }
DeepSkyBlue		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=191; yylval.cval[2]=255; return COLOR; }
SkyBlue			{ yylval.cval = malloc(3); yylval.cval[0]=135; yylval.cval[1]=206; yylval.cval[2]=235; return COLOR; }
LightSkyBlue		{ yylval.cval = malloc(3); yylval.cval[0]=135; yylval.cval[1]=206; yylval.cval[2]=250; return COLOR; }
SteelBlue		{ yylval.cval = malloc(3); yylval.cval[0]=70; yylval.cval[1]=130; yylval.cval[2]=180; return COLOR; }
LightSteelBlue		{ yylval.cval = malloc(3); yylval.cval[0]=176; yylval.cval[1]=196; yylval.cval[2]=222; return COLOR; }
LightBlue		{ yylval.cval = malloc(3); yylval.cval[0]=173; yylval.cval[1]=216; yylval.cval[2]=230; return COLOR; }
PowderBlue		{ yylval.cval = malloc(3); yylval.cval[0]=176; yylval.cval[1]=224; yylval.cval[2]=230; return COLOR; }
PaleTurquoise		{ yylval.cval = malloc(3); yylval.cval[0]=175; yylval.cval[1]=238; yylval.cval[2]=238; return COLOR; }
DarkTurquoise		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=206; yylval.cval[2]=209; return COLOR; }
MediumTurquoise		{ yylval.cval = malloc(3); yylval.cval[0]=72; yylval.cval[1]=209; yylval.cval[2]=204; return COLOR; }
turquoise		{ yylval.cval = malloc(3); yylval.cval[0]=64; yylval.cval[1]=224; yylval.cval[2]=208; return COLOR; }
cyan			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
LightCyan		{ yylval.cval = malloc(3); yylval.cval[0]=224; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
CadetBlue		{ yylval.cval = malloc(3); yylval.cval[0]=95; yylval.cval[1]=158; yylval.cval[2]=160; return COLOR; }
MediumAquamarine	{ yylval.cval = malloc(3); yylval.cval[0]=102; yylval.cval[1]=205; yylval.cval[2]=170; return COLOR; }
aquamarine		{ yylval.cval = malloc(3); yylval.cval[0]=127; yylval.cval[1]=255; yylval.cval[2]=212; return COLOR; }
DarkGreen		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=100; yylval.cval[2]=0; return COLOR; }
DarkOliveGreen		{ yylval.cval = malloc(3); yylval.cval[0]=85; yylval.cval[1]=107; yylval.cval[2]=47; return COLOR; }
DarkSeaGreen		{ yylval.cval = malloc(3); yylval.cval[0]=143; yylval.cval[1]=188; yylval.cval[2]=143; return COLOR; }
SeaGreen		{ yylval.cval = malloc(3); yylval.cval[0]=46; yylval.cval[1]=139; yylval.cval[2]=87; return COLOR; }
MediumSeaGreen		{ yylval.cval = malloc(3); yylval.cval[0]=60; yylval.cval[1]=179; yylval.cval[2]=113; return COLOR; }
LightSeaGreen		{ yylval.cval = malloc(3); yylval.cval[0]=32; yylval.cval[1]=178; yylval.cval[2]=170; return COLOR; }
PaleGreen		{ yylval.cval = malloc(3); yylval.cval[0]=152; yylval.cval[1]=251; yylval.cval[2]=152; return COLOR; }
SpringGreen		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=255; yylval.cval[2]=127; return COLOR; }
LawnGreen		{ yylval.cval = malloc(3); yylval.cval[0]=124; yylval.cval[1]=252; yylval.cval[2]=0; return COLOR; }
green			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=255; yylval.cval[2]=0; return COLOR; }
chartreuse		{ yylval.cval = malloc(3); yylval.cval[0]=127; yylval.cval[1]=255; yylval.cval[2]=0; return COLOR; }
MediumSpringGreen	{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=250; yylval.cval[2]=154; return COLOR; }
GreenYellow		{ yylval.cval = malloc(3); yylval.cval[0]=173; yylval.cval[1]=255; yylval.cval[2]=47; return COLOR; }
LimeGreen		{ yylval.cval = malloc(3); yylval.cval[0]=50; yylval.cval[1]=205; yylval.cval[2]=50; return COLOR; }
YellowGreen		{ yylval.cval = malloc(3); yylval.cval[0]=154; yylval.cval[1]=205; yylval.cval[2]=50; return COLOR; }
ForestGreen		{ yylval.cval = malloc(3); yylval.cval[0]=34; yylval.cval[1]=139; yylval.cval[2]=34; return COLOR; }
OliveDrab		{ yylval.cval = malloc(3); yylval.cval[0]=107; yylval.cval[1]=142; yylval.cval[2]=35; return COLOR; }
DarkKhaki		{ yylval.cval = malloc(3); yylval.cval[0]=189; yylval.cval[1]=183; yylval.cval[2]=107; return COLOR; }
khaki			{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=230; yylval.cval[2]=140; return COLOR; }
PaleGoldenrod		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=232; yylval.cval[2]=170; return COLOR; }
LightGoldenrodYellow	{ yylval.cval = malloc(3); yylval.cval[0]=250; yylval.cval[1]=250; yylval.cval[2]=210; return COLOR; }
LightYellow		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=224; return COLOR; }
yellow			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=0; return COLOR; }
gold			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=215; yylval.cval[2]=0; return COLOR; }
LightGoldenrod		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=221; yylval.cval[2]=130; return COLOR; }
goldenrod		{ yylval.cval = malloc(3); yylval.cval[0]=218; yylval.cval[1]=165; yylval.cval[2]=32; return COLOR; }
DarkGoldenrod		{ yylval.cval = malloc(3); yylval.cval[0]=184; yylval.cval[1]=134; yylval.cval[2]=11; return COLOR; }
RosyBrown		{ yylval.cval = malloc(3); yylval.cval[0]=188; yylval.cval[1]=143; yylval.cval[2]=143; return COLOR; }
IndianRed		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=92; yylval.cval[2]=92; return COLOR; }
SaddleBrown		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=69; yylval.cval[2]=19; return COLOR; }
sienna			{ yylval.cval = malloc(3); yylval.cval[0]=160; yylval.cval[1]=82; yylval.cval[2]=45; return COLOR; }
peru			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=133; yylval.cval[2]=63; return COLOR; }
burlywood		{ yylval.cval = malloc(3); yylval.cval[0]=222; yylval.cval[1]=184; yylval.cval[2]=135; return COLOR; }
beige			{ yylval.cval = malloc(3); yylval.cval[0]=245; yylval.cval[1]=245; yylval.cval[2]=220; return COLOR; }
wheat			{ yylval.cval = malloc(3); yylval.cval[0]=245; yylval.cval[1]=222; yylval.cval[2]=179; return COLOR; }
SandyBrown		{ yylval.cval = malloc(3); yylval.cval[0]=244; yylval.cval[1]=164; yylval.cval[2]=96; return COLOR; }
tan			{ yylval.cval = malloc(3); yylval.cval[0]=210; yylval.cval[1]=180; yylval.cval[2]=140; return COLOR; }
chocolate		{ yylval.cval = malloc(3); yylval.cval[0]=210; yylval.cval[1]=105; yylval.cval[2]=30; return COLOR; }
firebrick		{ yylval.cval = malloc(3); yylval.cval[0]=178; yylval.cval[1]=34; yylval.cval[2]=34; return COLOR; }
brown			{ yylval.cval = malloc(3); yylval.cval[0]=165; yylval.cval[1]=42; yylval.cval[2]=42; return COLOR; }
DarkSalmon		{ yylval.cval = malloc(3); yylval.cval[0]=233; yylval.cval[1]=150; yylval.cval[2]=122; return COLOR; }
salmon			{ yylval.cval = malloc(3); yylval.cval[0]=250; yylval.cval[1]=128; yylval.cval[2]=114; return COLOR; }
LightSalmon		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=160; yylval.cval[2]=122; return COLOR; }
orange			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=165; yylval.cval[2]=0; return COLOR; }
DarkOrange		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=140; yylval.cval[2]=0; return COLOR; }
coral			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=127; yylval.cval[2]=80; return COLOR; }
LightCoral		{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=128; yylval.cval[2]=128; return COLOR; }
tomato			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=99; yylval.cval[2]=71; return COLOR; }
OrangeRed		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=69; yylval.cval[2]=0; return COLOR; }
red			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
HotPink			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=105; yylval.cval[2]=180; return COLOR; }
DeepPink		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=20; yylval.cval[2]=147; return COLOR; }
pink			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=192; yylval.cval[2]=203; return COLOR; }
LightPink		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=182; yylval.cval[2]=193; return COLOR; }
PaleVioletRed		{ yylval.cval = malloc(3); yylval.cval[0]=219; yylval.cval[1]=112; yylval.cval[2]=147; return COLOR; }
maroon			{ yylval.cval = malloc(3); yylval.cval[0]=176; yylval.cval[1]=48; yylval.cval[2]=96; return COLOR; }
MediumVioletRed		{ yylval.cval = malloc(3); yylval.cval[0]=199; yylval.cval[1]=21; yylval.cval[2]=133; return COLOR; }
VioletRed		{ yylval.cval = malloc(3); yylval.cval[0]=208; yylval.cval[1]=32; yylval.cval[2]=144; return COLOR; }
magenta			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=0; yylval.cval[2]=255; return COLOR; }
violet			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=130; yylval.cval[2]=238; return COLOR; }
plum			{ yylval.cval = malloc(3); yylval.cval[0]=221; yylval.cval[1]=160; yylval.cval[2]=221; return COLOR; }
orchid			{ yylval.cval = malloc(3); yylval.cval[0]=218; yylval.cval[1]=112; yylval.cval[2]=214; return COLOR; }
MediumOrchid		{ yylval.cval = malloc(3); yylval.cval[0]=186; yylval.cval[1]=85; yylval.cval[2]=211; return COLOR; }
DarkOrchid		{ yylval.cval = malloc(3); yylval.cval[0]=153; yylval.cval[1]=50; yylval.cval[2]=204; return COLOR; }
DarkViolet		{ yylval.cval = malloc(3); yylval.cval[0]=148; yylval.cval[1]=0; yylval.cval[2]=211; return COLOR; }
BlueViolet		{ yylval.cval = malloc(3); yylval.cval[0]=138; yylval.cval[1]=43; yylval.cval[2]=226; return COLOR; }
purple			{ yylval.cval = malloc(3); yylval.cval[0]=160; yylval.cval[1]=32; yylval.cval[2]=240; return COLOR; }
MediumPurple		{ yylval.cval = malloc(3); yylval.cval[0]=147; yylval.cval[1]=112; yylval.cval[2]=219; return COLOR; }
thistle			{ yylval.cval = malloc(3); yylval.cval[0]=216; yylval.cval[1]=191; yylval.cval[2]=216; return COLOR; }
snow1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=250; yylval.cval[2]=250; return COLOR; }
snow2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=233; yylval.cval[2]=233; return COLOR; }
snow3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=201; yylval.cval[2]=201; return COLOR; }
snow4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=137; yylval.cval[2]=137; return COLOR; }
seashell1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=245; yylval.cval[2]=238; return COLOR; }
seashell2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=229; yylval.cval[2]=222; return COLOR; }
seashell3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=197; yylval.cval[2]=191; return COLOR; }
seashell4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=134; yylval.cval[2]=130; return COLOR; }
AntiqueWhite1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=239; yylval.cval[2]=219; return COLOR; }
AntiqueWhite2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=223; yylval.cval[2]=204; return COLOR; }
AntiqueWhite3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=192; yylval.cval[2]=176; return COLOR; }
AntiqueWhite4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=131; yylval.cval[2]=120; return COLOR; }
bisque1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=228; yylval.cval[2]=196; return COLOR; }
bisque2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=213; yylval.cval[2]=183; return COLOR; }
bisque3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=183; yylval.cval[2]=158; return COLOR; }
bisque4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=125; yylval.cval[2]=107; return COLOR; }
PeachPuff1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=218; yylval.cval[2]=185; return COLOR; }
PeachPuff2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=203; yylval.cval[2]=173; return COLOR; }
PeachPuff3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=175; yylval.cval[2]=149; return COLOR; }
PeachPuff4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=119; yylval.cval[2]=101; return COLOR; }
NavajoWhite1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=222; yylval.cval[2]=173; return COLOR; }
NavajoWhite2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=207; yylval.cval[2]=161; return COLOR; }
NavajoWhite3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=179; yylval.cval[2]=139; return COLOR; }
NavajoWhite4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=121; yylval.cval[2]=94; return COLOR; }
LemonChiffon1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=250; yylval.cval[2]=205; return COLOR; }
LemonChiffon2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=233; yylval.cval[2]=191; return COLOR; }
LemonChiffon3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=201; yylval.cval[2]=165; return COLOR; }
LemonChiffon4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=137; yylval.cval[2]=112; return COLOR; }
cornsilk1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=248; yylval.cval[2]=220; return COLOR; }
cornsilk2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=232; yylval.cval[2]=205; return COLOR; }
cornsilk3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=200; yylval.cval[2]=177; return COLOR; }
cornsilk4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=136; yylval.cval[2]=120; return COLOR; }
ivory1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=240; return COLOR; }
ivory2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=238; yylval.cval[2]=224; return COLOR; }
ivory3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=205; yylval.cval[2]=193; return COLOR; }
ivory4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=139; yylval.cval[2]=131; return COLOR; }
honeydew1		{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=255; yylval.cval[2]=240; return COLOR; }
honeydew2		{ yylval.cval = malloc(3); yylval.cval[0]=224; yylval.cval[1]=238; yylval.cval[2]=224; return COLOR; }
honeydew3		{ yylval.cval = malloc(3); yylval.cval[0]=193; yylval.cval[1]=205; yylval.cval[2]=193; return COLOR; }
honeydew4		{ yylval.cval = malloc(3); yylval.cval[0]=131; yylval.cval[1]=139; yylval.cval[2]=131; return COLOR; }
LavenderBlush1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=240; yylval.cval[2]=245; return COLOR; }
LavenderBlush2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=224; yylval.cval[2]=229; return COLOR; }
LavenderBlush3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=193; yylval.cval[2]=197; return COLOR; }
LavenderBlush4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=131; yylval.cval[2]=134; return COLOR; }
MistyRose1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=228; yylval.cval[2]=225; return COLOR; }
MistyRose2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=213; yylval.cval[2]=210; return COLOR; }
MistyRose3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=183; yylval.cval[2]=181; return COLOR; }
MistyRose4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=125; yylval.cval[2]=123; return COLOR; }
azure1			{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
azure2			{ yylval.cval = malloc(3); yylval.cval[0]=224; yylval.cval[1]=238; yylval.cval[2]=238; return COLOR; }
azure3			{ yylval.cval = malloc(3); yylval.cval[0]=193; yylval.cval[1]=205; yylval.cval[2]=205; return COLOR; }
azure4			{ yylval.cval = malloc(3); yylval.cval[0]=131; yylval.cval[1]=139; yylval.cval[2]=139; return COLOR; }
SlateBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=131; yylval.cval[1]=111; yylval.cval[2]=255; return COLOR; }
SlateBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=122; yylval.cval[1]=103; yylval.cval[2]=238; return COLOR; }
SlateBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=105; yylval.cval[1]=89; yylval.cval[2]=205; return COLOR; }
SlateBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=71; yylval.cval[1]=60; yylval.cval[2]=139; return COLOR; }
RoyalBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=72; yylval.cval[1]=118; yylval.cval[2]=255; return COLOR; }
RoyalBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=67; yylval.cval[1]=110; yylval.cval[2]=238; return COLOR; }
RoyalBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=58; yylval.cval[1]=95; yylval.cval[2]=205; return COLOR; }
RoyalBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=39; yylval.cval[1]=64; yylval.cval[2]=139; return COLOR; }
blue1			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=255; return COLOR; }
blue2			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=238; return COLOR; }
blue3			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=205; return COLOR; }
blue4			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=139; return COLOR; }
DodgerBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=30; yylval.cval[1]=144; yylval.cval[2]=255; return COLOR; }
DodgerBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=28; yylval.cval[1]=134; yylval.cval[2]=238; return COLOR; }
DodgerBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=24; yylval.cval[1]=116; yylval.cval[2]=205; return COLOR; }
DodgerBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=16; yylval.cval[1]=78; yylval.cval[2]=139; return COLOR; }
SteelBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=99; yylval.cval[1]=184; yylval.cval[2]=255; return COLOR; }
SteelBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=92; yylval.cval[1]=172; yylval.cval[2]=238; return COLOR; }
SteelBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=79; yylval.cval[1]=148; yylval.cval[2]=205; return COLOR; }
SteelBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=54; yylval.cval[1]=100; yylval.cval[2]=139; return COLOR; }
DeepSkyBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=191; yylval.cval[2]=255; return COLOR; }
DeepSkyBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=178; yylval.cval[2]=238; return COLOR; }
DeepSkyBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=154; yylval.cval[2]=205; return COLOR; }
DeepSkyBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=104; yylval.cval[2]=139; return COLOR; }
SkyBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=135; yylval.cval[1]=206; yylval.cval[2]=255; return COLOR; }
SkyBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=126; yylval.cval[1]=192; yylval.cval[2]=238; return COLOR; }
SkyBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=108; yylval.cval[1]=166; yylval.cval[2]=205; return COLOR; }
SkyBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=74; yylval.cval[1]=112; yylval.cval[2]=139; return COLOR; }
LightSkyBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=176; yylval.cval[1]=226; yylval.cval[2]=255; return COLOR; }
LightSkyBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=164; yylval.cval[1]=211; yylval.cval[2]=238; return COLOR; }
LightSkyBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=141; yylval.cval[1]=182; yylval.cval[2]=205; return COLOR; }
LightSkyBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=96; yylval.cval[1]=123; yylval.cval[2]=139; return COLOR; }
SlateGray1		{ yylval.cval = malloc(3); yylval.cval[0]=198; yylval.cval[1]=226; yylval.cval[2]=255; return COLOR; }
SlateGray2		{ yylval.cval = malloc(3); yylval.cval[0]=185; yylval.cval[1]=211; yylval.cval[2]=238; return COLOR; }
SlateGray3		{ yylval.cval = malloc(3); yylval.cval[0]=159; yylval.cval[1]=182; yylval.cval[2]=205; return COLOR; }
SlateGray4		{ yylval.cval = malloc(3); yylval.cval[0]=108; yylval.cval[1]=123; yylval.cval[2]=139; return COLOR; }
LightSteelBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=202; yylval.cval[1]=225; yylval.cval[2]=255; return COLOR; }
LightSteelBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=188; yylval.cval[1]=210; yylval.cval[2]=238; return COLOR; }
LightSteelBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=162; yylval.cval[1]=181; yylval.cval[2]=205; return COLOR; }
LightSteelBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=110; yylval.cval[1]=123; yylval.cval[2]=139; return COLOR; }
LightBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=191; yylval.cval[1]=239; yylval.cval[2]=255; return COLOR; }
LightBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=178; yylval.cval[1]=223; yylval.cval[2]=238; return COLOR; }
LightBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=154; yylval.cval[1]=192; yylval.cval[2]=205; return COLOR; }
LightBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=104; yylval.cval[1]=131; yylval.cval[2]=139; return COLOR; }
LightCyan1		{ yylval.cval = malloc(3); yylval.cval[0]=224; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
LightCyan2		{ yylval.cval = malloc(3); yylval.cval[0]=209; yylval.cval[1]=238; yylval.cval[2]=238; return COLOR; }
LightCyan3		{ yylval.cval = malloc(3); yylval.cval[0]=180; yylval.cval[1]=205; yylval.cval[2]=205; return COLOR; }
LightCyan4		{ yylval.cval = malloc(3); yylval.cval[0]=122; yylval.cval[1]=139; yylval.cval[2]=139; return COLOR; }
PaleTurquoise1		{ yylval.cval = malloc(3); yylval.cval[0]=187; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
PaleTurquoise2		{ yylval.cval = malloc(3); yylval.cval[0]=174; yylval.cval[1]=238; yylval.cval[2]=238; return COLOR; }
PaleTurquoise3		{ yylval.cval = malloc(3); yylval.cval[0]=150; yylval.cval[1]=205; yylval.cval[2]=205; return COLOR; }
PaleTurquoise4		{ yylval.cval = malloc(3); yylval.cval[0]=102; yylval.cval[1]=139; yylval.cval[2]=139; return COLOR; }
CadetBlue1		{ yylval.cval = malloc(3); yylval.cval[0]=152; yylval.cval[1]=245; yylval.cval[2]=255; return COLOR; }
CadetBlue2		{ yylval.cval = malloc(3); yylval.cval[0]=142; yylval.cval[1]=229; yylval.cval[2]=238; return COLOR; }
CadetBlue3		{ yylval.cval = malloc(3); yylval.cval[0]=122; yylval.cval[1]=197; yylval.cval[2]=205; return COLOR; }
CadetBlue4		{ yylval.cval = malloc(3); yylval.cval[0]=83; yylval.cval[1]=134; yylval.cval[2]=139; return COLOR; }
turquoise1		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=245; yylval.cval[2]=255; return COLOR; }
turquoise2		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=229; yylval.cval[2]=238; return COLOR; }
turquoise3		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=197; yylval.cval[2]=205; return COLOR; }
turquoise4		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=134; yylval.cval[2]=139; return COLOR; }
cyan1			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
cyan2			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=238; yylval.cval[2]=238; return COLOR; }
cyan3			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=205; yylval.cval[2]=205; return COLOR; }
cyan4			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=139; yylval.cval[2]=139; return COLOR; }
DarkSlateGray1		{ yylval.cval = malloc(3); yylval.cval[0]=151; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
DarkSlateGray2		{ yylval.cval = malloc(3); yylval.cval[0]=141; yylval.cval[1]=238; yylval.cval[2]=238; return COLOR; }
DarkSlateGray3		{ yylval.cval = malloc(3); yylval.cval[0]=121; yylval.cval[1]=205; yylval.cval[2]=205; return COLOR; }
DarkSlateGray4		{ yylval.cval = malloc(3); yylval.cval[0]=82; yylval.cval[1]=139; yylval.cval[2]=139; return COLOR; }
aquamarine1		{ yylval.cval = malloc(3); yylval.cval[0]=127; yylval.cval[1]=255; yylval.cval[2]=212; return COLOR; }
aquamarine2		{ yylval.cval = malloc(3); yylval.cval[0]=118; yylval.cval[1]=238; yylval.cval[2]=198; return COLOR; }
aquamarine3		{ yylval.cval = malloc(3); yylval.cval[0]=102; yylval.cval[1]=205; yylval.cval[2]=170; return COLOR; }
aquamarine4		{ yylval.cval = malloc(3); yylval.cval[0]=69; yylval.cval[1]=139; yylval.cval[2]=116; return COLOR; }
DarkSeaGreen1		{ yylval.cval = malloc(3); yylval.cval[0]=193; yylval.cval[1]=255; yylval.cval[2]=193; return COLOR; }
DarkSeaGreen2		{ yylval.cval = malloc(3); yylval.cval[0]=180; yylval.cval[1]=238; yylval.cval[2]=180; return COLOR; }
DarkSeaGreen3		{ yylval.cval = malloc(3); yylval.cval[0]=155; yylval.cval[1]=205; yylval.cval[2]=155; return COLOR; }
DarkSeaGreen4		{ yylval.cval = malloc(3); yylval.cval[0]=105; yylval.cval[1]=139; yylval.cval[2]=105; return COLOR; }
SeaGreen1		{ yylval.cval = malloc(3); yylval.cval[0]=84; yylval.cval[1]=255; yylval.cval[2]=159; return COLOR; }
SeaGreen2		{ yylval.cval = malloc(3); yylval.cval[0]=78; yylval.cval[1]=238; yylval.cval[2]=148; return COLOR; }
SeaGreen3		{ yylval.cval = malloc(3); yylval.cval[0]=67; yylval.cval[1]=205; yylval.cval[2]=128; return COLOR; }
SeaGreen4		{ yylval.cval = malloc(3); yylval.cval[0]=46; yylval.cval[1]=139; yylval.cval[2]=87; return COLOR; }
PaleGreen1		{ yylval.cval = malloc(3); yylval.cval[0]=154; yylval.cval[1]=255; yylval.cval[2]=154; return COLOR; }
PaleGreen2		{ yylval.cval = malloc(3); yylval.cval[0]=144; yylval.cval[1]=238; yylval.cval[2]=144; return COLOR; }
PaleGreen3		{ yylval.cval = malloc(3); yylval.cval[0]=124; yylval.cval[1]=205; yylval.cval[2]=124; return COLOR; }
PaleGreen4		{ yylval.cval = malloc(3); yylval.cval[0]=84; yylval.cval[1]=139; yylval.cval[2]=84; return COLOR; }
SpringGreen1		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=255; yylval.cval[2]=127; return COLOR; }
SpringGreen2		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=238; yylval.cval[2]=118; return COLOR; }
SpringGreen3		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=205; yylval.cval[2]=102; return COLOR; }
SpringGreen4		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=139; yylval.cval[2]=69; return COLOR; }
green1			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=255; yylval.cval[2]=0; return COLOR; }
green2			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=238; yylval.cval[2]=0; return COLOR; }
green3			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=205; yylval.cval[2]=0; return COLOR; }
green4			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=139; yylval.cval[2]=0; return COLOR; }
chartreuse1		{ yylval.cval = malloc(3); yylval.cval[0]=127; yylval.cval[1]=255; yylval.cval[2]=0; return COLOR; }
chartreuse2		{ yylval.cval = malloc(3); yylval.cval[0]=118; yylval.cval[1]=238; yylval.cval[2]=0; return COLOR; }
chartreuse3		{ yylval.cval = malloc(3); yylval.cval[0]=102; yylval.cval[1]=205; yylval.cval[2]=0; return COLOR; }
chartreuse4		{ yylval.cval = malloc(3); yylval.cval[0]=69; yylval.cval[1]=139; yylval.cval[2]=0; return COLOR; }
OliveDrab1		{ yylval.cval = malloc(3); yylval.cval[0]=192; yylval.cval[1]=255; yylval.cval[2]=62; return COLOR; }
OliveDrab2		{ yylval.cval = malloc(3); yylval.cval[0]=179; yylval.cval[1]=238; yylval.cval[2]=58; return COLOR; }
OliveDrab3		{ yylval.cval = malloc(3); yylval.cval[0]=154; yylval.cval[1]=205; yylval.cval[2]=50; return COLOR; }
OliveDrab4		{ yylval.cval = malloc(3); yylval.cval[0]=105; yylval.cval[1]=139; yylval.cval[2]=34; return COLOR; }
DarkOliveGreen1		{ yylval.cval = malloc(3); yylval.cval[0]=202; yylval.cval[1]=255; yylval.cval[2]=112; return COLOR; }
DarkOliveGreen2		{ yylval.cval = malloc(3); yylval.cval[0]=188; yylval.cval[1]=238; yylval.cval[2]=104; return COLOR; }
DarkOliveGreen3		{ yylval.cval = malloc(3); yylval.cval[0]=162; yylval.cval[1]=205; yylval.cval[2]=90; return COLOR; }
DarkOliveGreen4		{ yylval.cval = malloc(3); yylval.cval[0]=110; yylval.cval[1]=139; yylval.cval[2]=61; return COLOR; }
khaki1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=246; yylval.cval[2]=143; return COLOR; }
khaki2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=230; yylval.cval[2]=133; return COLOR; }
khaki3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=198; yylval.cval[2]=115; return COLOR; }
khaki4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=134; yylval.cval[2]=78; return COLOR; }
LightGoldenrod1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=236; yylval.cval[2]=139; return COLOR; }
LightGoldenrod2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=220; yylval.cval[2]=130; return COLOR; }
LightGoldenrod3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=190; yylval.cval[2]=112; return COLOR; }
LightGoldenrod4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=129; yylval.cval[2]=76; return COLOR; }
LightYellow1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=224; return COLOR; }
LightYellow2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=238; yylval.cval[2]=209; return COLOR; }
LightYellow3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=205; yylval.cval[2]=180; return COLOR; }
LightYellow4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=139; yylval.cval[2]=122; return COLOR; }
yellow1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=0; return COLOR; }
yellow2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=238; yylval.cval[2]=0; return COLOR; }
yellow3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=205; yylval.cval[2]=0; return COLOR; }
yellow4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=139; yylval.cval[2]=0; return COLOR; }
gold1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=215; yylval.cval[2]=0; return COLOR; }
gold2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=201; yylval.cval[2]=0; return COLOR; }
gold3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=173; yylval.cval[2]=0; return COLOR; }
gold4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=117; yylval.cval[2]=0; return COLOR; }
goldenrod1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=193; yylval.cval[2]=37; return COLOR; }
goldenrod2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=180; yylval.cval[2]=34; return COLOR; }
goldenrod3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=155; yylval.cval[2]=29; return COLOR; }
goldenrod4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=105; yylval.cval[2]=20; return COLOR; }
DarkGoldenrod1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=185; yylval.cval[2]=15; return COLOR; }
DarkGoldenrod2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=173; yylval.cval[2]=14; return COLOR; }
DarkGoldenrod3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=149; yylval.cval[2]=12; return COLOR; }
DarkGoldenrod4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=101; yylval.cval[2]=8; return COLOR; }
RosyBrown1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=193; yylval.cval[2]=193; return COLOR; }
RosyBrown2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=180; yylval.cval[2]=180; return COLOR; }
RosyBrown3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=155; yylval.cval[2]=155; return COLOR; }
RosyBrown4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=105; yylval.cval[2]=105; return COLOR; }
IndianRed1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=106; yylval.cval[2]=106; return COLOR; }
IndianRed2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=99; yylval.cval[2]=99; return COLOR; }
IndianRed3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=85; yylval.cval[2]=85; return COLOR; }
IndianRed4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=58; yylval.cval[2]=58; return COLOR; }
sienna1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=130; yylval.cval[2]=71; return COLOR; }
sienna2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=121; yylval.cval[2]=66; return COLOR; }
sienna3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=104; yylval.cval[2]=57; return COLOR; }
sienna4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=71; yylval.cval[2]=38; return COLOR; }
burlywood1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=211; yylval.cval[2]=155; return COLOR; }
burlywood2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=197; yylval.cval[2]=145; return COLOR; }
burlywood3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=170; yylval.cval[2]=125; return COLOR; }
burlywood4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=115; yylval.cval[2]=85; return COLOR; }
wheat1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=231; yylval.cval[2]=186; return COLOR; }
wheat2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=216; yylval.cval[2]=174; return COLOR; }
wheat3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=186; yylval.cval[2]=150; return COLOR; }
wheat4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=126; yylval.cval[2]=102; return COLOR; }
tan1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=165; yylval.cval[2]=79; return COLOR; }
tan2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=154; yylval.cval[2]=73; return COLOR; }
tan3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=133; yylval.cval[2]=63; return COLOR; }
tan4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=90; yylval.cval[2]=43; return COLOR; }
chocolate1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=127; yylval.cval[2]=36; return COLOR; }
chocolate2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=118; yylval.cval[2]=33; return COLOR; }
chocolate3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=102; yylval.cval[2]=29; return COLOR; }
chocolate4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=69; yylval.cval[2]=19; return COLOR; }
firebrick1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=48; yylval.cval[2]=48; return COLOR; }
firebrick2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=44; yylval.cval[2]=44; return COLOR; }
firebrick3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=38; yylval.cval[2]=38; return COLOR; }
firebrick4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=26; yylval.cval[2]=26; return COLOR; }
brown1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=64; yylval.cval[2]=64; return COLOR; }
brown2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=59; yylval.cval[2]=59; return COLOR; }
brown3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=51; yylval.cval[2]=51; return COLOR; }
brown4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=35; yylval.cval[2]=35; return COLOR; }
salmon1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=140; yylval.cval[2]=105; return COLOR; }
salmon2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=130; yylval.cval[2]=98; return COLOR; }
salmon3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=112; yylval.cval[2]=84; return COLOR; }
salmon4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=76; yylval.cval[2]=57; return COLOR; }
LightSalmon1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=160; yylval.cval[2]=122; return COLOR; }
LightSalmon2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=149; yylval.cval[2]=114; return COLOR; }
LightSalmon3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=129; yylval.cval[2]=98; return COLOR; }
LightSalmon4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=87; yylval.cval[2]=66; return COLOR; }
orange1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=165; yylval.cval[2]=0; return COLOR; }
orange2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=154; yylval.cval[2]=0; return COLOR; }
orange3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=133; yylval.cval[2]=0; return COLOR; }
orange4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=90; yylval.cval[2]=0; return COLOR; }
DarkOrange1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=127; yylval.cval[2]=0; return COLOR; }
DarkOrange2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=118; yylval.cval[2]=0; return COLOR; }
DarkOrange3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=102; yylval.cval[2]=0; return COLOR; }
DarkOrange4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=69; yylval.cval[2]=0; return COLOR; }
coral1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=114; yylval.cval[2]=86; return COLOR; }
coral2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=106; yylval.cval[2]=80; return COLOR; }
coral3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=91; yylval.cval[2]=69; return COLOR; }
coral4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=62; yylval.cval[2]=47; return COLOR; }
tomato1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=99; yylval.cval[2]=71; return COLOR; }
tomato2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=92; yylval.cval[2]=66; return COLOR; }
tomato3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=79; yylval.cval[2]=57; return COLOR; }
tomato4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=54; yylval.cval[2]=38; return COLOR; }
OrangeRed1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=69; yylval.cval[2]=0; return COLOR; }
OrangeRed2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=64; yylval.cval[2]=0; return COLOR; }
OrangeRed3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=55; yylval.cval[2]=0; return COLOR; }
OrangeRed4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=37; yylval.cval[2]=0; return COLOR; }
red1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
red2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
red3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
red4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
DeepPink1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=20; yylval.cval[2]=147; return COLOR; }
DeepPink2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=18; yylval.cval[2]=137; return COLOR; }
DeepPink3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=16; yylval.cval[2]=118; return COLOR; }
DeepPink4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=10; yylval.cval[2]=80; return COLOR; }
HotPink1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=110; yylval.cval[2]=180; return COLOR; }
HotPink2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=106; yylval.cval[2]=167; return COLOR; }
HotPink3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=96; yylval.cval[2]=144; return COLOR; }
HotPink4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=58; yylval.cval[2]=98; return COLOR; }
pink1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=181; yylval.cval[2]=197; return COLOR; }
pink2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=169; yylval.cval[2]=184; return COLOR; }
pink3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=145; yylval.cval[2]=158; return COLOR; }
pink4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=99; yylval.cval[2]=108; return COLOR; }
LightPink1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=174; yylval.cval[2]=185; return COLOR; }
LightPink2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=162; yylval.cval[2]=173; return COLOR; }
LightPink3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=140; yylval.cval[2]=149; return COLOR; }
LightPink4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=95; yylval.cval[2]=101; return COLOR; }
PaleVioletRed1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=130; yylval.cval[2]=171; return COLOR; }
PaleVioletRed2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=121; yylval.cval[2]=159; return COLOR; }
PaleVioletRed3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=104; yylval.cval[2]=137; return COLOR; }
PaleVioletRed4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=71; yylval.cval[2]=93; return COLOR; }
maroon1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=52; yylval.cval[2]=179; return COLOR; }
maroon2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=48; yylval.cval[2]=167; return COLOR; }
maroon3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=41; yylval.cval[2]=144; return COLOR; }
maroon4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=28; yylval.cval[2]=98; return COLOR; }
VioletRed1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=62; yylval.cval[2]=150; return COLOR; }
VioletRed2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=58; yylval.cval[2]=140; return COLOR; }
VioletRed3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=50; yylval.cval[2]=120; return COLOR; }
VioletRed4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=34; yylval.cval[2]=82; return COLOR; }
magenta1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=0; yylval.cval[2]=255; return COLOR; }
magenta2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=0; yylval.cval[2]=238; return COLOR; }
magenta3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=0; yylval.cval[2]=205; return COLOR; }
magenta4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=0; yylval.cval[2]=139; return COLOR; }
orchid1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=131; yylval.cval[2]=250; return COLOR; }
orchid2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=122; yylval.cval[2]=233; return COLOR; }
orchid3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=105; yylval.cval[2]=201; return COLOR; }
orchid4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=71; yylval.cval[2]=137; return COLOR; }
plum1			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=187; yylval.cval[2]=255; return COLOR; }
plum2			{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=174; yylval.cval[2]=238; return COLOR; }
plum3			{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=150; yylval.cval[2]=205; return COLOR; }
plum4			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=102; yylval.cval[2]=139; return COLOR; }
MediumOrchid1		{ yylval.cval = malloc(3); yylval.cval[0]=224; yylval.cval[1]=102; yylval.cval[2]=255; return COLOR; }
MediumOrchid2		{ yylval.cval = malloc(3); yylval.cval[0]=209; yylval.cval[1]=95; yylval.cval[2]=238; return COLOR; }
MediumOrchid3		{ yylval.cval = malloc(3); yylval.cval[0]=180; yylval.cval[1]=82; yylval.cval[2]=205; return COLOR; }
MediumOrchid4		{ yylval.cval = malloc(3); yylval.cval[0]=122; yylval.cval[1]=55; yylval.cval[2]=139; return COLOR; }
DarkOrchid1		{ yylval.cval = malloc(3); yylval.cval[0]=191; yylval.cval[1]=62; yylval.cval[2]=255; return COLOR; }
DarkOrchid2		{ yylval.cval = malloc(3); yylval.cval[0]=178; yylval.cval[1]=58; yylval.cval[2]=238; return COLOR; }
DarkOrchid3		{ yylval.cval = malloc(3); yylval.cval[0]=154; yylval.cval[1]=50; yylval.cval[2]=205; return COLOR; }
DarkOrchid4		{ yylval.cval = malloc(3); yylval.cval[0]=104; yylval.cval[1]=34; yylval.cval[2]=139; return COLOR; }
purple1			{ yylval.cval = malloc(3); yylval.cval[0]=155; yylval.cval[1]=48; yylval.cval[2]=255; return COLOR; }
purple2			{ yylval.cval = malloc(3); yylval.cval[0]=145; yylval.cval[1]=44; yylval.cval[2]=238; return COLOR; }
purple3			{ yylval.cval = malloc(3); yylval.cval[0]=125; yylval.cval[1]=38; yylval.cval[2]=205; return COLOR; }
purple4			{ yylval.cval = malloc(3); yylval.cval[0]=85; yylval.cval[1]=26; yylval.cval[2]=139; return COLOR; }
MediumPurple1		{ yylval.cval = malloc(3); yylval.cval[0]=171; yylval.cval[1]=130; yylval.cval[2]=255; return COLOR; }
MediumPurple2		{ yylval.cval = malloc(3); yylval.cval[0]=159; yylval.cval[1]=121; yylval.cval[2]=238; return COLOR; }
MediumPurple3		{ yylval.cval = malloc(3); yylval.cval[0]=137; yylval.cval[1]=104; yylval.cval[2]=205; return COLOR; }
MediumPurple4		{ yylval.cval = malloc(3); yylval.cval[0]=93; yylval.cval[1]=71; yylval.cval[2]=139; return COLOR; }
thistle1		{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=225; yylval.cval[2]=255; return COLOR; }
thistle2		{ yylval.cval = malloc(3); yylval.cval[0]=238; yylval.cval[1]=210; yylval.cval[2]=238; return COLOR; }
thistle3		{ yylval.cval = malloc(3); yylval.cval[0]=205; yylval.cval[1]=181; yylval.cval[2]=205; return COLOR; }
thistle4		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=123; yylval.cval[2]=139; return COLOR; }
gray0			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
grey0			{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
gray1			{ yylval.cval = malloc(3); yylval.cval[0]=3; yylval.cval[1]=3; yylval.cval[2]=3; return COLOR; }
grey1			{ yylval.cval = malloc(3); yylval.cval[0]=3; yylval.cval[1]=3; yylval.cval[2]=3; return COLOR; }
gray2			{ yylval.cval = malloc(3); yylval.cval[0]=5; yylval.cval[1]=5; yylval.cval[2]=5; return COLOR; }
grey2			{ yylval.cval = malloc(3); yylval.cval[0]=5; yylval.cval[1]=5; yylval.cval[2]=5; return COLOR; }
gray3			{ yylval.cval = malloc(3); yylval.cval[0]=8; yylval.cval[1]=8; yylval.cval[2]=8; return COLOR; }
grey3			{ yylval.cval = malloc(3); yylval.cval[0]=8; yylval.cval[1]=8; yylval.cval[2]=8; return COLOR; }
gray4			{ yylval.cval = malloc(3); yylval.cval[0]=10; yylval.cval[1]=10; yylval.cval[2]=10; return COLOR; }
grey4			{ yylval.cval = malloc(3); yylval.cval[0]=10; yylval.cval[1]=10; yylval.cval[2]=10; return COLOR; }
gray5			{ yylval.cval = malloc(3); yylval.cval[0]=13; yylval.cval[1]=13; yylval.cval[2]=13; return COLOR; }
grey5			{ yylval.cval = malloc(3); yylval.cval[0]=13; yylval.cval[1]=13; yylval.cval[2]=13; return COLOR; }
gray6			{ yylval.cval = malloc(3); yylval.cval[0]=15; yylval.cval[1]=15; yylval.cval[2]=15; return COLOR; }
grey6			{ yylval.cval = malloc(3); yylval.cval[0]=15; yylval.cval[1]=15; yylval.cval[2]=15; return COLOR; }
gray7			{ yylval.cval = malloc(3); yylval.cval[0]=18; yylval.cval[1]=18; yylval.cval[2]=18; return COLOR; }
grey7			{ yylval.cval = malloc(3); yylval.cval[0]=18; yylval.cval[1]=18; yylval.cval[2]=18; return COLOR; }
gray8			{ yylval.cval = malloc(3); yylval.cval[0]=20; yylval.cval[1]=20; yylval.cval[2]=20; return COLOR; }
grey8			{ yylval.cval = malloc(3); yylval.cval[0]=20; yylval.cval[1]=20; yylval.cval[2]=20; return COLOR; }
gray9			{ yylval.cval = malloc(3); yylval.cval[0]=23; yylval.cval[1]=23; yylval.cval[2]=23; return COLOR; }
grey9			{ yylval.cval = malloc(3); yylval.cval[0]=23; yylval.cval[1]=23; yylval.cval[2]=23; return COLOR; }
gray10			{ yylval.cval = malloc(3); yylval.cval[0]=26; yylval.cval[1]=26; yylval.cval[2]=26; return COLOR; }
grey10			{ yylval.cval = malloc(3); yylval.cval[0]=26; yylval.cval[1]=26; yylval.cval[2]=26; return COLOR; }
gray11			{ yylval.cval = malloc(3); yylval.cval[0]=28; yylval.cval[1]=28; yylval.cval[2]=28; return COLOR; }
grey11			{ yylval.cval = malloc(3); yylval.cval[0]=28; yylval.cval[1]=28; yylval.cval[2]=28; return COLOR; }
gray12			{ yylval.cval = malloc(3); yylval.cval[0]=31; yylval.cval[1]=31; yylval.cval[2]=31; return COLOR; }
grey12			{ yylval.cval = malloc(3); yylval.cval[0]=31; yylval.cval[1]=31; yylval.cval[2]=31; return COLOR; }
gray13			{ yylval.cval = malloc(3); yylval.cval[0]=33; yylval.cval[1]=33; yylval.cval[2]=33; return COLOR; }
grey13			{ yylval.cval = malloc(3); yylval.cval[0]=33; yylval.cval[1]=33; yylval.cval[2]=33; return COLOR; }
gray14			{ yylval.cval = malloc(3); yylval.cval[0]=36; yylval.cval[1]=36; yylval.cval[2]=36; return COLOR; }
grey14			{ yylval.cval = malloc(3); yylval.cval[0]=36; yylval.cval[1]=36; yylval.cval[2]=36; return COLOR; }
gray15			{ yylval.cval = malloc(3); yylval.cval[0]=38; yylval.cval[1]=38; yylval.cval[2]=38; return COLOR; }
grey15			{ yylval.cval = malloc(3); yylval.cval[0]=38; yylval.cval[1]=38; yylval.cval[2]=38; return COLOR; }
gray16			{ yylval.cval = malloc(3); yylval.cval[0]=41; yylval.cval[1]=41; yylval.cval[2]=41; return COLOR; }
grey16			{ yylval.cval = malloc(3); yylval.cval[0]=41; yylval.cval[1]=41; yylval.cval[2]=41; return COLOR; }
gray17			{ yylval.cval = malloc(3); yylval.cval[0]=43; yylval.cval[1]=43; yylval.cval[2]=43; return COLOR; }
grey17			{ yylval.cval = malloc(3); yylval.cval[0]=43; yylval.cval[1]=43; yylval.cval[2]=43; return COLOR; }
gray18			{ yylval.cval = malloc(3); yylval.cval[0]=46; yylval.cval[1]=46; yylval.cval[2]=46; return COLOR; }
grey18			{ yylval.cval = malloc(3); yylval.cval[0]=46; yylval.cval[1]=46; yylval.cval[2]=46; return COLOR; }
gray19			{ yylval.cval = malloc(3); yylval.cval[0]=48; yylval.cval[1]=48; yylval.cval[2]=48; return COLOR; }
grey19			{ yylval.cval = malloc(3); yylval.cval[0]=48; yylval.cval[1]=48; yylval.cval[2]=48; return COLOR; }
gray20			{ yylval.cval = malloc(3); yylval.cval[0]=51; yylval.cval[1]=51; yylval.cval[2]=51; return COLOR; }
grey20			{ yylval.cval = malloc(3); yylval.cval[0]=51; yylval.cval[1]=51; yylval.cval[2]=51; return COLOR; }
gray21			{ yylval.cval = malloc(3); yylval.cval[0]=54; yylval.cval[1]=54; yylval.cval[2]=54; return COLOR; }
grey21			{ yylval.cval = malloc(3); yylval.cval[0]=54; yylval.cval[1]=54; yylval.cval[2]=54; return COLOR; }
gray22			{ yylval.cval = malloc(3); yylval.cval[0]=56; yylval.cval[1]=56; yylval.cval[2]=56; return COLOR; }
grey22			{ yylval.cval = malloc(3); yylval.cval[0]=56; yylval.cval[1]=56; yylval.cval[2]=56; return COLOR; }
gray23			{ yylval.cval = malloc(3); yylval.cval[0]=59; yylval.cval[1]=59; yylval.cval[2]=59; return COLOR; }
grey23			{ yylval.cval = malloc(3); yylval.cval[0]=59; yylval.cval[1]=59; yylval.cval[2]=59; return COLOR; }
gray24			{ yylval.cval = malloc(3); yylval.cval[0]=61; yylval.cval[1]=61; yylval.cval[2]=61; return COLOR; }
grey24			{ yylval.cval = malloc(3); yylval.cval[0]=61; yylval.cval[1]=61; yylval.cval[2]=61; return COLOR; }
gray25			{ yylval.cval = malloc(3); yylval.cval[0]=64; yylval.cval[1]=64; yylval.cval[2]=64; return COLOR; }
grey25			{ yylval.cval = malloc(3); yylval.cval[0]=64; yylval.cval[1]=64; yylval.cval[2]=64; return COLOR; }
gray26			{ yylval.cval = malloc(3); yylval.cval[0]=66; yylval.cval[1]=66; yylval.cval[2]=66; return COLOR; }
grey26			{ yylval.cval = malloc(3); yylval.cval[0]=66; yylval.cval[1]=66; yylval.cval[2]=66; return COLOR; }
gray27			{ yylval.cval = malloc(3); yylval.cval[0]=69; yylval.cval[1]=69; yylval.cval[2]=69; return COLOR; }
grey27			{ yylval.cval = malloc(3); yylval.cval[0]=69; yylval.cval[1]=69; yylval.cval[2]=69; return COLOR; }
gray28			{ yylval.cval = malloc(3); yylval.cval[0]=71; yylval.cval[1]=71; yylval.cval[2]=71; return COLOR; }
grey28			{ yylval.cval = malloc(3); yylval.cval[0]=71; yylval.cval[1]=71; yylval.cval[2]=71; return COLOR; }
gray29			{ yylval.cval = malloc(3); yylval.cval[0]=74; yylval.cval[1]=74; yylval.cval[2]=74; return COLOR; }
grey29			{ yylval.cval = malloc(3); yylval.cval[0]=74; yylval.cval[1]=74; yylval.cval[2]=74; return COLOR; }
gray30			{ yylval.cval = malloc(3); yylval.cval[0]=77; yylval.cval[1]=77; yylval.cval[2]=77; return COLOR; }
grey30			{ yylval.cval = malloc(3); yylval.cval[0]=77; yylval.cval[1]=77; yylval.cval[2]=77; return COLOR; }
gray31			{ yylval.cval = malloc(3); yylval.cval[0]=79; yylval.cval[1]=79; yylval.cval[2]=79; return COLOR; }
grey31			{ yylval.cval = malloc(3); yylval.cval[0]=79; yylval.cval[1]=79; yylval.cval[2]=79; return COLOR; }
gray32			{ yylval.cval = malloc(3); yylval.cval[0]=82; yylval.cval[1]=82; yylval.cval[2]=82; return COLOR; }
grey32			{ yylval.cval = malloc(3); yylval.cval[0]=82; yylval.cval[1]=82; yylval.cval[2]=82; return COLOR; }
gray33			{ yylval.cval = malloc(3); yylval.cval[0]=84; yylval.cval[1]=84; yylval.cval[2]=84; return COLOR; }
grey33			{ yylval.cval = malloc(3); yylval.cval[0]=84; yylval.cval[1]=84; yylval.cval[2]=84; return COLOR; }
gray34			{ yylval.cval = malloc(3); yylval.cval[0]=87; yylval.cval[1]=87; yylval.cval[2]=87; return COLOR; }
grey34			{ yylval.cval = malloc(3); yylval.cval[0]=87; yylval.cval[1]=87; yylval.cval[2]=87; return COLOR; }
gray35			{ yylval.cval = malloc(3); yylval.cval[0]=89; yylval.cval[1]=89; yylval.cval[2]=89; return COLOR; }
grey35			{ yylval.cval = malloc(3); yylval.cval[0]=89; yylval.cval[1]=89; yylval.cval[2]=89; return COLOR; }
gray36			{ yylval.cval = malloc(3); yylval.cval[0]=92; yylval.cval[1]=92; yylval.cval[2]=92; return COLOR; }
grey36			{ yylval.cval = malloc(3); yylval.cval[0]=92; yylval.cval[1]=92; yylval.cval[2]=92; return COLOR; }
gray37			{ yylval.cval = malloc(3); yylval.cval[0]=94; yylval.cval[1]=94; yylval.cval[2]=94; return COLOR; }
grey37			{ yylval.cval = malloc(3); yylval.cval[0]=94; yylval.cval[1]=94; yylval.cval[2]=94; return COLOR; }
gray38			{ yylval.cval = malloc(3); yylval.cval[0]=97; yylval.cval[1]=97; yylval.cval[2]=97; return COLOR; }
grey38			{ yylval.cval = malloc(3); yylval.cval[0]=97; yylval.cval[1]=97; yylval.cval[2]=97; return COLOR; }
gray39			{ yylval.cval = malloc(3); yylval.cval[0]=99; yylval.cval[1]=99; yylval.cval[2]=99; return COLOR; }
grey39			{ yylval.cval = malloc(3); yylval.cval[0]=99; yylval.cval[1]=99; yylval.cval[2]=99; return COLOR; }
gray40			{ yylval.cval = malloc(3); yylval.cval[0]=102; yylval.cval[1]=102; yylval.cval[2]=102; return COLOR; }
grey40			{ yylval.cval = malloc(3); yylval.cval[0]=102; yylval.cval[1]=102; yylval.cval[2]=102; return COLOR; }
gray41			{ yylval.cval = malloc(3); yylval.cval[0]=105; yylval.cval[1]=105; yylval.cval[2]=105; return COLOR; }
grey41			{ yylval.cval = malloc(3); yylval.cval[0]=105; yylval.cval[1]=105; yylval.cval[2]=105; return COLOR; }
gray42			{ yylval.cval = malloc(3); yylval.cval[0]=107; yylval.cval[1]=107; yylval.cval[2]=107; return COLOR; }
grey42			{ yylval.cval = malloc(3); yylval.cval[0]=107; yylval.cval[1]=107; yylval.cval[2]=107; return COLOR; }
gray43			{ yylval.cval = malloc(3); yylval.cval[0]=110; yylval.cval[1]=110; yylval.cval[2]=110; return COLOR; }
grey43			{ yylval.cval = malloc(3); yylval.cval[0]=110; yylval.cval[1]=110; yylval.cval[2]=110; return COLOR; }
gray44			{ yylval.cval = malloc(3); yylval.cval[0]=112; yylval.cval[1]=112; yylval.cval[2]=112; return COLOR; }
grey44			{ yylval.cval = malloc(3); yylval.cval[0]=112; yylval.cval[1]=112; yylval.cval[2]=112; return COLOR; }
gray45			{ yylval.cval = malloc(3); yylval.cval[0]=115; yylval.cval[1]=115; yylval.cval[2]=115; return COLOR; }
grey45			{ yylval.cval = malloc(3); yylval.cval[0]=115; yylval.cval[1]=115; yylval.cval[2]=115; return COLOR; }
gray46			{ yylval.cval = malloc(3); yylval.cval[0]=117; yylval.cval[1]=117; yylval.cval[2]=117; return COLOR; }
grey46			{ yylval.cval = malloc(3); yylval.cval[0]=117; yylval.cval[1]=117; yylval.cval[2]=117; return COLOR; }
gray47			{ yylval.cval = malloc(3); yylval.cval[0]=120; yylval.cval[1]=120; yylval.cval[2]=120; return COLOR; }
grey47			{ yylval.cval = malloc(3); yylval.cval[0]=120; yylval.cval[1]=120; yylval.cval[2]=120; return COLOR; }
gray48			{ yylval.cval = malloc(3); yylval.cval[0]=122; yylval.cval[1]=122; yylval.cval[2]=122; return COLOR; }
grey48			{ yylval.cval = malloc(3); yylval.cval[0]=122; yylval.cval[1]=122; yylval.cval[2]=122; return COLOR; }
gray49			{ yylval.cval = malloc(3); yylval.cval[0]=125; yylval.cval[1]=125; yylval.cval[2]=125; return COLOR; }
grey49			{ yylval.cval = malloc(3); yylval.cval[0]=125; yylval.cval[1]=125; yylval.cval[2]=125; return COLOR; }
gray50			{ yylval.cval = malloc(3); yylval.cval[0]=127; yylval.cval[1]=127; yylval.cval[2]=127; return COLOR; }
grey50			{ yylval.cval = malloc(3); yylval.cval[0]=127; yylval.cval[1]=127; yylval.cval[2]=127; return COLOR; }
gray51			{ yylval.cval = malloc(3); yylval.cval[0]=130; yylval.cval[1]=130; yylval.cval[2]=130; return COLOR; }
grey51			{ yylval.cval = malloc(3); yylval.cval[0]=130; yylval.cval[1]=130; yylval.cval[2]=130; return COLOR; }
gray52			{ yylval.cval = malloc(3); yylval.cval[0]=133; yylval.cval[1]=133; yylval.cval[2]=133; return COLOR; }
grey52			{ yylval.cval = malloc(3); yylval.cval[0]=133; yylval.cval[1]=133; yylval.cval[2]=133; return COLOR; }
gray53			{ yylval.cval = malloc(3); yylval.cval[0]=135; yylval.cval[1]=135; yylval.cval[2]=135; return COLOR; }
grey53			{ yylval.cval = malloc(3); yylval.cval[0]=135; yylval.cval[1]=135; yylval.cval[2]=135; return COLOR; }
gray54			{ yylval.cval = malloc(3); yylval.cval[0]=138; yylval.cval[1]=138; yylval.cval[2]=138; return COLOR; }
grey54			{ yylval.cval = malloc(3); yylval.cval[0]=138; yylval.cval[1]=138; yylval.cval[2]=138; return COLOR; }
gray55			{ yylval.cval = malloc(3); yylval.cval[0]=140; yylval.cval[1]=140; yylval.cval[2]=140; return COLOR; }
grey55			{ yylval.cval = malloc(3); yylval.cval[0]=140; yylval.cval[1]=140; yylval.cval[2]=140; return COLOR; }
gray56			{ yylval.cval = malloc(3); yylval.cval[0]=143; yylval.cval[1]=143; yylval.cval[2]=143; return COLOR; }
grey56			{ yylval.cval = malloc(3); yylval.cval[0]=143; yylval.cval[1]=143; yylval.cval[2]=143; return COLOR; }
gray57			{ yylval.cval = malloc(3); yylval.cval[0]=145; yylval.cval[1]=145; yylval.cval[2]=145; return COLOR; }
grey57			{ yylval.cval = malloc(3); yylval.cval[0]=145; yylval.cval[1]=145; yylval.cval[2]=145; return COLOR; }
gray58			{ yylval.cval = malloc(3); yylval.cval[0]=148; yylval.cval[1]=148; yylval.cval[2]=148; return COLOR; }
grey58			{ yylval.cval = malloc(3); yylval.cval[0]=148; yylval.cval[1]=148; yylval.cval[2]=148; return COLOR; }
gray59			{ yylval.cval = malloc(3); yylval.cval[0]=150; yylval.cval[1]=150; yylval.cval[2]=150; return COLOR; }
grey59			{ yylval.cval = malloc(3); yylval.cval[0]=150; yylval.cval[1]=150; yylval.cval[2]=150; return COLOR; }
gray60			{ yylval.cval = malloc(3); yylval.cval[0]=153; yylval.cval[1]=153; yylval.cval[2]=153; return COLOR; }
grey60			{ yylval.cval = malloc(3); yylval.cval[0]=153; yylval.cval[1]=153; yylval.cval[2]=153; return COLOR; }
gray61			{ yylval.cval = malloc(3); yylval.cval[0]=156; yylval.cval[1]=156; yylval.cval[2]=156; return COLOR; }
grey61			{ yylval.cval = malloc(3); yylval.cval[0]=156; yylval.cval[1]=156; yylval.cval[2]=156; return COLOR; }
gray62			{ yylval.cval = malloc(3); yylval.cval[0]=158; yylval.cval[1]=158; yylval.cval[2]=158; return COLOR; }
grey62			{ yylval.cval = malloc(3); yylval.cval[0]=158; yylval.cval[1]=158; yylval.cval[2]=158; return COLOR; }
gray63			{ yylval.cval = malloc(3); yylval.cval[0]=161; yylval.cval[1]=161; yylval.cval[2]=161; return COLOR; }
grey63			{ yylval.cval = malloc(3); yylval.cval[0]=161; yylval.cval[1]=161; yylval.cval[2]=161; return COLOR; }
gray64			{ yylval.cval = malloc(3); yylval.cval[0]=163; yylval.cval[1]=163; yylval.cval[2]=163; return COLOR; }
grey64			{ yylval.cval = malloc(3); yylval.cval[0]=163; yylval.cval[1]=163; yylval.cval[2]=163; return COLOR; }
gray65			{ yylval.cval = malloc(3); yylval.cval[0]=166; yylval.cval[1]=166; yylval.cval[2]=166; return COLOR; }
grey65			{ yylval.cval = malloc(3); yylval.cval[0]=166; yylval.cval[1]=166; yylval.cval[2]=166; return COLOR; }
gray66			{ yylval.cval = malloc(3); yylval.cval[0]=168; yylval.cval[1]=168; yylval.cval[2]=168; return COLOR; }
grey66			{ yylval.cval = malloc(3); yylval.cval[0]=168; yylval.cval[1]=168; yylval.cval[2]=168; return COLOR; }
gray67			{ yylval.cval = malloc(3); yylval.cval[0]=171; yylval.cval[1]=171; yylval.cval[2]=171; return COLOR; }
grey67			{ yylval.cval = malloc(3); yylval.cval[0]=171; yylval.cval[1]=171; yylval.cval[2]=171; return COLOR; }
gray68			{ yylval.cval = malloc(3); yylval.cval[0]=173; yylval.cval[1]=173; yylval.cval[2]=173; return COLOR; }
grey68			{ yylval.cval = malloc(3); yylval.cval[0]=173; yylval.cval[1]=173; yylval.cval[2]=173; return COLOR; }
gray69			{ yylval.cval = malloc(3); yylval.cval[0]=176; yylval.cval[1]=176; yylval.cval[2]=176; return COLOR; }
grey69			{ yylval.cval = malloc(3); yylval.cval[0]=176; yylval.cval[1]=176; yylval.cval[2]=176; return COLOR; }
gray70			{ yylval.cval = malloc(3); yylval.cval[0]=179; yylval.cval[1]=179; yylval.cval[2]=179; return COLOR; }
grey70			{ yylval.cval = malloc(3); yylval.cval[0]=179; yylval.cval[1]=179; yylval.cval[2]=179; return COLOR; }
gray71			{ yylval.cval = malloc(3); yylval.cval[0]=181; yylval.cval[1]=181; yylval.cval[2]=181; return COLOR; }
grey71			{ yylval.cval = malloc(3); yylval.cval[0]=181; yylval.cval[1]=181; yylval.cval[2]=181; return COLOR; }
gray72			{ yylval.cval = malloc(3); yylval.cval[0]=184; yylval.cval[1]=184; yylval.cval[2]=184; return COLOR; }
grey72			{ yylval.cval = malloc(3); yylval.cval[0]=184; yylval.cval[1]=184; yylval.cval[2]=184; return COLOR; }
gray73			{ yylval.cval = malloc(3); yylval.cval[0]=186; yylval.cval[1]=186; yylval.cval[2]=186; return COLOR; }
grey73			{ yylval.cval = malloc(3); yylval.cval[0]=186; yylval.cval[1]=186; yylval.cval[2]=186; return COLOR; }
gray74			{ yylval.cval = malloc(3); yylval.cval[0]=189; yylval.cval[1]=189; yylval.cval[2]=189; return COLOR; }
grey74			{ yylval.cval = malloc(3); yylval.cval[0]=189; yylval.cval[1]=189; yylval.cval[2]=189; return COLOR; }
gray75			{ yylval.cval = malloc(3); yylval.cval[0]=191; yylval.cval[1]=191; yylval.cval[2]=191; return COLOR; }
grey75			{ yylval.cval = malloc(3); yylval.cval[0]=191; yylval.cval[1]=191; yylval.cval[2]=191; return COLOR; }
gray76			{ yylval.cval = malloc(3); yylval.cval[0]=194; yylval.cval[1]=194; yylval.cval[2]=194; return COLOR; }
grey76			{ yylval.cval = malloc(3); yylval.cval[0]=194; yylval.cval[1]=194; yylval.cval[2]=194; return COLOR; }
gray77			{ yylval.cval = malloc(3); yylval.cval[0]=196; yylval.cval[1]=196; yylval.cval[2]=196; return COLOR; }
grey77			{ yylval.cval = malloc(3); yylval.cval[0]=196; yylval.cval[1]=196; yylval.cval[2]=196; return COLOR; }
gray78			{ yylval.cval = malloc(3); yylval.cval[0]=199; yylval.cval[1]=199; yylval.cval[2]=199; return COLOR; }
grey78			{ yylval.cval = malloc(3); yylval.cval[0]=199; yylval.cval[1]=199; yylval.cval[2]=199; return COLOR; }
gray79			{ yylval.cval = malloc(3); yylval.cval[0]=201; yylval.cval[1]=201; yylval.cval[2]=201; return COLOR; }
grey79			{ yylval.cval = malloc(3); yylval.cval[0]=201; yylval.cval[1]=201; yylval.cval[2]=201; return COLOR; }
gray80			{ yylval.cval = malloc(3); yylval.cval[0]=204; yylval.cval[1]=204; yylval.cval[2]=204; return COLOR; }
grey80			{ yylval.cval = malloc(3); yylval.cval[0]=204; yylval.cval[1]=204; yylval.cval[2]=204; return COLOR; }
gray81			{ yylval.cval = malloc(3); yylval.cval[0]=207; yylval.cval[1]=207; yylval.cval[2]=207; return COLOR; }
grey81			{ yylval.cval = malloc(3); yylval.cval[0]=207; yylval.cval[1]=207; yylval.cval[2]=207; return COLOR; }
gray82			{ yylval.cval = malloc(3); yylval.cval[0]=209; yylval.cval[1]=209; yylval.cval[2]=209; return COLOR; }
grey82			{ yylval.cval = malloc(3); yylval.cval[0]=209; yylval.cval[1]=209; yylval.cval[2]=209; return COLOR; }
gray83			{ yylval.cval = malloc(3); yylval.cval[0]=212; yylval.cval[1]=212; yylval.cval[2]=212; return COLOR; }
grey83			{ yylval.cval = malloc(3); yylval.cval[0]=212; yylval.cval[1]=212; yylval.cval[2]=212; return COLOR; }
gray84			{ yylval.cval = malloc(3); yylval.cval[0]=214; yylval.cval[1]=214; yylval.cval[2]=214; return COLOR; }
grey84			{ yylval.cval = malloc(3); yylval.cval[0]=214; yylval.cval[1]=214; yylval.cval[2]=214; return COLOR; }
gray85			{ yylval.cval = malloc(3); yylval.cval[0]=217; yylval.cval[1]=217; yylval.cval[2]=217; return COLOR; }
grey85			{ yylval.cval = malloc(3); yylval.cval[0]=217; yylval.cval[1]=217; yylval.cval[2]=217; return COLOR; }
gray86			{ yylval.cval = malloc(3); yylval.cval[0]=219; yylval.cval[1]=219; yylval.cval[2]=219; return COLOR; }
grey86			{ yylval.cval = malloc(3); yylval.cval[0]=219; yylval.cval[1]=219; yylval.cval[2]=219; return COLOR; }
gray87			{ yylval.cval = malloc(3); yylval.cval[0]=222; yylval.cval[1]=222; yylval.cval[2]=222; return COLOR; }
grey87			{ yylval.cval = malloc(3); yylval.cval[0]=222; yylval.cval[1]=222; yylval.cval[2]=222; return COLOR; }
gray88			{ yylval.cval = malloc(3); yylval.cval[0]=224; yylval.cval[1]=224; yylval.cval[2]=224; return COLOR; }
grey88			{ yylval.cval = malloc(3); yylval.cval[0]=224; yylval.cval[1]=224; yylval.cval[2]=224; return COLOR; }
gray89			{ yylval.cval = malloc(3); yylval.cval[0]=227; yylval.cval[1]=227; yylval.cval[2]=227; return COLOR; }
grey89			{ yylval.cval = malloc(3); yylval.cval[0]=227; yylval.cval[1]=227; yylval.cval[2]=227; return COLOR; }
gray90			{ yylval.cval = malloc(3); yylval.cval[0]=229; yylval.cval[1]=229; yylval.cval[2]=229; return COLOR; }
grey90			{ yylval.cval = malloc(3); yylval.cval[0]=229; yylval.cval[1]=229; yylval.cval[2]=229; return COLOR; }
gray91			{ yylval.cval = malloc(3); yylval.cval[0]=232; yylval.cval[1]=232; yylval.cval[2]=232; return COLOR; }
grey91			{ yylval.cval = malloc(3); yylval.cval[0]=232; yylval.cval[1]=232; yylval.cval[2]=232; return COLOR; }
gray92			{ yylval.cval = malloc(3); yylval.cval[0]=235; yylval.cval[1]=235; yylval.cval[2]=235; return COLOR; }
grey92			{ yylval.cval = malloc(3); yylval.cval[0]=235; yylval.cval[1]=235; yylval.cval[2]=235; return COLOR; }
gray93			{ yylval.cval = malloc(3); yylval.cval[0]=237; yylval.cval[1]=237; yylval.cval[2]=237; return COLOR; }
grey93			{ yylval.cval = malloc(3); yylval.cval[0]=237; yylval.cval[1]=237; yylval.cval[2]=237; return COLOR; }
gray94			{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=240; yylval.cval[2]=240; return COLOR; }
grey94			{ yylval.cval = malloc(3); yylval.cval[0]=240; yylval.cval[1]=240; yylval.cval[2]=240; return COLOR; }
gray95			{ yylval.cval = malloc(3); yylval.cval[0]=242; yylval.cval[1]=242; yylval.cval[2]=242; return COLOR; }
grey95			{ yylval.cval = malloc(3); yylval.cval[0]=242; yylval.cval[1]=242; yylval.cval[2]=242; return COLOR; }
gray96			{ yylval.cval = malloc(3); yylval.cval[0]=245; yylval.cval[1]=245; yylval.cval[2]=245; return COLOR; }
grey96			{ yylval.cval = malloc(3); yylval.cval[0]=245; yylval.cval[1]=245; yylval.cval[2]=245; return COLOR; }
gray97			{ yylval.cval = malloc(3); yylval.cval[0]=247; yylval.cval[1]=247; yylval.cval[2]=247; return COLOR; }
grey97			{ yylval.cval = malloc(3); yylval.cval[0]=247; yylval.cval[1]=247; yylval.cval[2]=247; return COLOR; }
gray98			{ yylval.cval = malloc(3); yylval.cval[0]=250; yylval.cval[1]=250; yylval.cval[2]=250; return COLOR; }
grey98			{ yylval.cval = malloc(3); yylval.cval[0]=250; yylval.cval[1]=250; yylval.cval[2]=250; return COLOR; }
gray99			{ yylval.cval = malloc(3); yylval.cval[0]=252; yylval.cval[1]=252; yylval.cval[2]=252; return COLOR; }
grey99			{ yylval.cval = malloc(3); yylval.cval[0]=252; yylval.cval[1]=252; yylval.cval[2]=252; return COLOR; }
gray100			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
grey100			{ yylval.cval = malloc(3); yylval.cval[0]=255; yylval.cval[1]=255; yylval.cval[2]=255; return COLOR; }
DarkGrey		{ yylval.cval = malloc(3); yylval.cval[0]=169; yylval.cval[1]=169; yylval.cval[2]=169; return COLOR; }
DarkGray		{ yylval.cval = malloc(3); yylval.cval[0]=169; yylval.cval[1]=169; yylval.cval[2]=169; return COLOR; }
DarkBlue		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=0; yylval.cval[2]=139; return COLOR; }
DarkCyan		{ yylval.cval = malloc(3); yylval.cval[0]=0; yylval.cval[1]=139; yylval.cval[2]=139; return COLOR; }
DarkMagenta		{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=0; yylval.cval[2]=139; return COLOR; }
DarkRed			{ yylval.cval = malloc(3); yylval.cval[0]=139; yylval.cval[1]=0; yylval.cval[2]=0; return COLOR; }
LightGreen		{ yylval.cval = malloc(3); yylval.cval[0]=144; yylval.cval[1]=238; yylval.cval[2]=144; return COLOR; }

\".*\"			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return STRING;
\'.*\'			yytext[strlen(yytext)-1] = '\0'; yylval.cval = strdup(yytext+1); return STRING;
[a-zA-Z][a-zA-Z0-9\.]*	yylval.cval = strdup(yytext); return ID;
[\-]?[0-9]*[\.]?[0-9]*	yylval.dval = strtod(yytext, (char**)NULL); return NUM;

\:           		return COLON;
[\ \t]			; // ignore spaces
\n			line_no++;

%%
