#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "color.h"

unsigned char* color_get(char* desc)
{
	unsigned char* c = malloc(3);
	if(strcmp(desc, "snow") == 0)
	{
		c[0] = 255;
		c[1] = 250;
		c[2] = 250;
	}
	else if(strcmp(desc, "GhostWhite") == 0)
	{
		c[0] = 248;
		c[1] = 248;
		c[2] = 255;
	}
	else if(strcmp(desc, "WhiteSmoke") == 0)
	{
		c[0] = 245;
		c[1] = 245;
		c[2] = 245;
	}
	else if(strcmp(desc, "gainsboro") == 0)
	{
		c[0] = 220;
		c[1] = 220;
		c[2] = 220;
	}
	else if(strcmp(desc, "FloralWhite") == 0)
	{
		c[0] = 255;
		c[1] = 250;
		c[2] = 240;
	}
	else if(strcmp(desc, "OldLace") == 0)
	{
		c[0] = 253;
		c[1] = 245;
		c[2] = 230;
	}
	else if(strcmp(desc, "linen") == 0)
	{
		c[0] = 250;
		c[1] = 240;
		c[2] = 230;
	}
	else if(strcmp(desc, "AntiqueWhite") == 0)
	{
		c[0] = 250;
		c[1] = 235;
		c[2] = 215;
	}
	else if(strcmp(desc, "PapayaWhip") == 0)
	{
		c[0] = 255;
		c[1] = 239;
		c[2] = 213;
	}
	else if(strcmp(desc, "BlanchedAlmond") == 0)
	{
		c[0] = 255;
		c[1] = 235;
		c[2] = 205;
	}
	else if(strcmp(desc, "bisque") == 0)
	{
		c[0] = 255;
		c[1] = 228;
		c[2] = 196;
	}
	else if(strcmp(desc, "PeachPuff") == 0)
	{
		c[0] = 255;
		c[1] = 218;
		c[2] = 185;
	}
	else if(strcmp(desc, "NavajoWhite") == 0)
	{
		c[0] = 255;
		c[1] = 222;
		c[2] = 173;
	}
	else if(strcmp(desc, "moccasin") == 0)
	{
		c[0] = 255;
		c[1] = 228;
		c[2] = 181;
	}
	else if(strcmp(desc, "cornsilk") == 0)
	{
		c[0] = 255;
		c[1] = 248;
		c[2] = 220;
	}
	else if(strcmp(desc, "ivory") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 240;
	}
	else if(strcmp(desc, "LemonChiffon") == 0)
	{
		c[0] = 255;
		c[1] = 250;
		c[2] = 205;
	}
	else if(strcmp(desc, "seashell") == 0)
	{
		c[0] = 255;
		c[1] = 245;
		c[2] = 238;
	}
	else if(strcmp(desc, "honeydew") == 0)
	{
		c[0] = 240;
		c[1] = 255;
		c[2] = 240;
	}
	else if(strcmp(desc, "MintCream") == 0)
	{
		c[0] = 245;
		c[1] = 255;
		c[2] = 250;
	}
	else if(strcmp(desc, "azure") == 0)
	{
		c[0] = 240;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "AliceBlue") == 0)
	{
		c[0] = 240;
		c[1] = 248;
		c[2] = 255;
	}
	else if(strcmp(desc, "lavender") == 0)
	{
		c[0] = 230;
		c[1] = 230;
		c[2] = 250;
	}
	else if(strcmp(desc, "LavenderBlush") == 0)
	{
		c[0] = 255;
		c[1] = 240;
		c[2] = 245;
	}
	else if(strcmp(desc, "MistyRose") == 0)
	{
		c[0] = 255;
		c[1] = 228;
		c[2] = 225;
	}
	else if(strcmp(desc, "white") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "black") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "DarkSlateGray") == 0)
	{
		c[0] = 47;
		c[1] = 79;
		c[2] = 79;
	}
	else if(strcmp(desc, "DarkSlateGrey") == 0)
	{
		c[0] = 47;
		c[1] = 79;
		c[2] = 79;
	}
	else if(strcmp(desc, "DimGray") == 0)
	{
		c[0] = 105;
		c[1] = 105;
		c[2] = 105;
	}
	else if(strcmp(desc, "DimGrey") == 0)
	{
		c[0] = 105;
		c[1] = 105;
		c[2] = 105;
	}
	else if(strcmp(desc, "SlateGray") == 0)
	{
		c[0] = 112;
		c[1] = 128;
		c[2] = 144;
	}
	else if(strcmp(desc, "SlateGrey") == 0)
	{
		c[0] = 112;
		c[1] = 128;
		c[2] = 144;
	}
	else if(strcmp(desc, "LightSlateGray") == 0)
	{
		c[0] = 119;
		c[1] = 136;
		c[2] = 153;
	}
	else if(strcmp(desc, "LightSlateGrey") == 0)
	{
		c[0] = 119;
		c[1] = 136;
		c[2] = 153;
	}
	else if(strcmp(desc, "gray") == 0)
	{
		c[0] = 190;
		c[1] = 190;
		c[2] = 190;
	}
	else if(strcmp(desc, "grey") == 0)
	{
		c[0] = 190;
		c[1] = 190;
		c[2] = 190;
	}
	else if(strcmp(desc, "LightGrey") == 0)
	{
		c[0] = 211;
		c[1] = 211;
		c[2] = 211;
	}
	else if(strcmp(desc, "LightGray") == 0)
	{
		c[0] = 211;
		c[1] = 211;
		c[2] = 211;
	}
	else if(strcmp(desc, "MidnightBlue") == 0)
	{
		c[0] = 25;
		c[1] = 25;
		c[2] = 112;
	}
	else if(strcmp(desc, "navy") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 128;
	}
	else if(strcmp(desc, "NavyBlue") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 128;
	}
	else if(strcmp(desc, "CornflowerBlue") == 0)
	{
		c[0] = 100;
		c[1] = 149;
		c[2] = 237;
	}
	else if(strcmp(desc, "DarkSlateBlue") == 0)
	{
		c[0] = 72;
		c[1] = 61;
		c[2] = 139;
	}
	else if(strcmp(desc, "SlateBlue") == 0)
	{
		c[0] = 106;
		c[1] = 90;
		c[2] = 205;
	}
	else if(strcmp(desc, "MediumSlateBlue") == 0)
	{
		c[0] = 123;
		c[1] = 104;
		c[2] = 238;
	}
	else if(strcmp(desc, "LightSlateBlue") == 0)
	{
		c[0] = 132;
		c[1] = 112;
		c[2] = 255;
	}
	else if(strcmp(desc, "MediumBlue") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 205;
	}
	else if(strcmp(desc, "RoyalBlue") == 0)
	{
		c[0] = 65;
		c[1] = 105;
		c[2] = 225;
	}
	else if(strcmp(desc, "blue") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 255;
	}
	else if(strcmp(desc, "DodgerBlue") == 0)
	{
		c[0] = 30;
		c[1] = 144;
		c[2] = 255;
	}
	else if(strcmp(desc, "DeepSkyBlue") == 0)
	{
		c[0] = 0;
		c[1] = 191;
		c[2] = 255;
	}
	else if(strcmp(desc, "SkyBlue") == 0)
	{
		c[0] = 135;
		c[1] = 206;
		c[2] = 235;
	}
	else if(strcmp(desc, "LightSkyBlue") == 0)
	{
		c[0] = 135;
		c[1] = 206;
		c[2] = 250;
	}
	else if(strcmp(desc, "SteelBlue") == 0)
	{
		c[0] = 70;
		c[1] = 130;
		c[2] = 180;
	}
	else if(strcmp(desc, "LightSteelBlue") == 0)
	{
		c[0] = 176;
		c[1] = 196;
		c[2] = 222;
	}
	else if(strcmp(desc, "LightBlue") == 0)
	{
		c[0] = 173;
		c[1] = 216;
		c[2] = 230;
	}
	else if(strcmp(desc, "PowderBlue") == 0)
	{
		c[0] = 176;
		c[1] = 224;
		c[2] = 230;
	}
	else if(strcmp(desc, "PaleTurquoise") == 0)
	{
		c[0] = 175;
		c[1] = 238;
		c[2] = 238;
	}
	else if(strcmp(desc, "DarkTurquoise") == 0)
	{
		c[0] = 0;
		c[1] = 206;
		c[2] = 209;
	}
	else if(strcmp(desc, "MediumTurquoise") == 0)
	{
		c[0] = 72;
		c[1] = 209;
		c[2] = 204;
	}
	else if(strcmp(desc, "turquoise") == 0)
	{
		c[0] = 64;
		c[1] = 224;
		c[2] = 208;
	}
	else if(strcmp(desc, "cyan") == 0)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "LightCyan") == 0)
	{
		c[0] = 224;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "CadetBlue") == 0)
	{
		c[0] = 95;
		c[1] = 158;
		c[2] = 160;
	}
	else if(strcmp(desc, "MediumAquamarine") == 0)
	{
		c[0] = 102;
		c[1] = 205;
		c[2] = 170;
	}
	else if(strcmp(desc, "aquamarine") == 0)
	{
		c[0] = 127;
		c[1] = 255;
		c[2] = 212;
	}
	else if(strcmp(desc, "DarkGreen") == 0)
	{
		c[0] = 0;
		c[1] = 100;
		c[2] = 0;
	}
	else if(strcmp(desc, "DarkOliveGreen") == 0)
	{
		c[0] = 85;
		c[1] = 107;
		c[2] = 47;
	}
	else if(strcmp(desc, "DarkSeaGreen") == 0)
	{
		c[0] = 143;
		c[1] = 188;
		c[2] = 143;
	}
	else if(strcmp(desc, "SeaGreen") == 0)
	{
		c[0] = 46;
		c[1] = 139;
		c[2] = 87;
	}
	else if(strcmp(desc, "MediumSeaGreen") == 0)
	{
		c[0] = 60;
		c[1] = 179;
		c[2] = 113;
	}
	else if(strcmp(desc, "LightSeaGreen") == 0)
	{
		c[0] = 32;
		c[1] = 178;
		c[2] = 170;
	}
	else if(strcmp(desc, "PaleGreen") == 0)
	{
		c[0] = 152;
		c[1] = 251;
		c[2] = 152;
	}
	else if(strcmp(desc, "SpringGreen") == 0)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = 127;
	}
	else if(strcmp(desc, "LawnGreen") == 0)
	{
		c[0] = 124;
		c[1] = 252;
		c[2] = 0;
	}
	else if(strcmp(desc, "green") == 0)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = 0;
	}
	else if(strcmp(desc, "chartreuse") == 0)
	{
		c[0] = 127;
		c[1] = 255;
		c[2] = 0;
	}
	else if(strcmp(desc, "MediumSpringGreen") == 0)
	{
		c[0] = 0;
		c[1] = 250;
		c[2] = 154;
	}
	else if(strcmp(desc, "GreenYellow") == 0)
	{
		c[0] = 173;
		c[1] = 255;
		c[2] = 47;
	}
	else if(strcmp(desc, "LimeGreen") == 0)
	{
		c[0] = 50;
		c[1] = 205;
		c[2] = 50;
	}
	else if(strcmp(desc, "YellowGreen") == 0)
	{
		c[0] = 154;
		c[1] = 205;
		c[2] = 50;
	}
	else if(strcmp(desc, "ForestGreen") == 0)
	{
		c[0] = 34;
		c[1] = 139;
		c[2] = 34;
	}
	else if(strcmp(desc, "OliveDrab") == 0)
	{
		c[0] = 107;
		c[1] = 142;
		c[2] = 35;
	}
	else if(strcmp(desc, "DarkKhaki") == 0)
	{
		c[0] = 189;
		c[1] = 183;
		c[2] = 107;
	}
	else if(strcmp(desc, "khaki") == 0)
	{
		c[0] = 240;
		c[1] = 230;
		c[2] = 140;
	}
	else if(strcmp(desc, "PaleGoldenrod") == 0)
	{
		c[0] = 238;
		c[1] = 232;
		c[2] = 170;
	}
	else if(strcmp(desc, "LightGoldenrodYellow") == 0)
	{
		c[0] = 250;
		c[1] = 250;
		c[2] = 210;
	}
	else if(strcmp(desc, "LightYellow") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 224;
	}
	else if(strcmp(desc, "yellow") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 0;
	}
	else if(strcmp(desc, "gold") == 0)
	{
		c[0] = 255;
		c[1] = 215;
		c[2] = 0;
	}
	else if(strcmp(desc, "LightGoldenrod") == 0)
	{
		c[0] = 238;
		c[1] = 221;
		c[2] = 130;
	}
	else if(strcmp(desc, "goldenrod") == 0)
	{
		c[0] = 218;
		c[1] = 165;
		c[2] = 32;
	}
	else if(strcmp(desc, "DarkGoldenrod") == 0)
	{
		c[0] = 184;
		c[1] = 134;
		c[2] = 11;
	}
	else if(strcmp(desc, "RosyBrown") == 0)
	{
		c[0] = 188;
		c[1] = 143;
		c[2] = 143;
	}
	else if(strcmp(desc, "IndianRed") == 0)
	{
		c[0] = 205;
		c[1] = 92;
		c[2] = 92;
	}
	else if(strcmp(desc, "SaddleBrown") == 0)
	{
		c[0] = 139;
		c[1] = 69;
		c[2] = 19;
	}
	else if(strcmp(desc, "sienna") == 0)
	{
		c[0] = 160;
		c[1] = 82;
		c[2] = 45;
	}
	else if(strcmp(desc, "peru") == 0)
	{
		c[0] = 205;
		c[1] = 133;
		c[2] = 63;
	}
	else if(strcmp(desc, "burlywood") == 0)
	{
		c[0] = 222;
		c[1] = 184;
		c[2] = 135;
	}
	else if(strcmp(desc, "beige") == 0)
	{
		c[0] = 245;
		c[1] = 245;
		c[2] = 220;
	}
	else if(strcmp(desc, "wheat") == 0)
	{
		c[0] = 245;
		c[1] = 222;
		c[2] = 179;
	}
	else if(strcmp(desc, "SandyBrown") == 0)
	{
		c[0] = 244;
		c[1] = 164;
		c[2] = 96;
	}
	else if(strcmp(desc, "tan") == 0)
	{
		c[0] = 210;
		c[1] = 180;
		c[2] = 140;
	}
	else if(strcmp(desc, "chocolate") == 0)
	{
		c[0] = 210;
		c[1] = 105;
		c[2] = 30;
	}
	else if(strcmp(desc, "firebrick") == 0)
	{
		c[0] = 178;
		c[1] = 34;
		c[2] = 34;
	}
	else if(strcmp(desc, "brown") == 0)
	{
		c[0] = 165;
		c[1] = 42;
		c[2] = 42;
	}
	else if(strcmp(desc, "DarkSalmon") == 0)
	{
		c[0] = 233;
		c[1] = 150;
		c[2] = 122;
	}
	else if(strcmp(desc, "salmon") == 0)
	{
		c[0] = 250;
		c[1] = 128;
		c[2] = 114;
	}
	else if(strcmp(desc, "LightSalmon") == 0)
	{
		c[0] = 255;
		c[1] = 160;
		c[2] = 122;
	}
	else if(strcmp(desc, "orange") == 0)
	{
		c[0] = 255;
		c[1] = 165;
		c[2] = 0;
	}
	else if(strcmp(desc, "DarkOrange") == 0)
	{
		c[0] = 255;
		c[1] = 140;
		c[2] = 0;
	}
	else if(strcmp(desc, "coral") == 0)
	{
		c[0] = 255;
		c[1] = 127;
		c[2] = 80;
	}
	else if(strcmp(desc, "LightCoral") == 0)
	{
		c[0] = 240;
		c[1] = 128;
		c[2] = 128;
	}
	else if(strcmp(desc, "tomato") == 0)
	{
		c[0] = 255;
		c[1] = 99;
		c[2] = 71;
	}
	else if(strcmp(desc, "OrangeRed") == 0)
	{
		c[0] = 255;
		c[1] = 69;
		c[2] = 0;
	}
	else if(strcmp(desc, "red") == 0)
	{
		c[0] = 255;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "HotPink") == 0)
	{
		c[0] = 255;
		c[1] = 105;
		c[2] = 180;
	}
	else if(strcmp(desc, "DeepPink") == 0)
	{
		c[0] = 255;
		c[1] = 20;
		c[2] = 147;
	}
	else if(strcmp(desc, "pink") == 0)
	{
		c[0] = 255;
		c[1] = 192;
		c[2] = 203;
	}
	else if(strcmp(desc, "LightPink") == 0)
	{
		c[0] = 255;
		c[1] = 182;
		c[2] = 193;
	}
	else if(strcmp(desc, "PaleVioletRed") == 0)
	{
		c[0] = 219;
		c[1] = 112;
		c[2] = 147;
	}
	else if(strcmp(desc, "maroon") == 0)
	{
		c[0] = 176;
		c[1] = 48;
		c[2] = 96;
	}
	else if(strcmp(desc, "MediumVioletRed") == 0)
	{
		c[0] = 199;
		c[1] = 21;
		c[2] = 133;
	}
	else if(strcmp(desc, "VioletRed") == 0)
	{
		c[0] = 208;
		c[1] = 32;
		c[2] = 144;
	}
	else if(strcmp(desc, "magenta") == 0)
	{
		c[0] = 255;
		c[1] = 0;
		c[2] = 255;
	}
	else if(strcmp(desc, "violet") == 0)
	{
		c[0] = 238;
		c[1] = 130;
		c[2] = 238;
	}
	else if(strcmp(desc, "plum") == 0)
	{
		c[0] = 221;
		c[1] = 160;
		c[2] = 221;
	}
	else if(strcmp(desc, "orchid") == 0)
	{
		c[0] = 218;
		c[1] = 112;
		c[2] = 214;
	}
	else if(strcmp(desc, "MediumOrchid") == 0)
	{
		c[0] = 186;
		c[1] = 85;
		c[2] = 211;
	}
	else if(strcmp(desc, "DarkOrchid") == 0)
	{
		c[0] = 153;
		c[1] = 50;
		c[2] = 204;
	}
	else if(strcmp(desc, "DarkViolet") == 0)
	{
		c[0] = 148;
		c[1] = 0;
		c[2] = 211;
	}
	else if(strcmp(desc, "BlueViolet") == 0)
	{
		c[0] = 138;
		c[1] = 43;
		c[2] = 226;
	}
	else if(strcmp(desc, "purple") == 0)
	{
		c[0] = 160;
		c[1] = 32;
		c[2] = 240;
	}
	else if(strcmp(desc, "MediumPurple") == 0)
	{
		c[0] = 147;
		c[1] = 112;
		c[2] = 219;
	}
	else if(strcmp(desc, "thistle") == 0)
	{
		c[0] = 216;
		c[1] = 191;
		c[2] = 216;
	}
	else if(strcmp(desc, "snow1") == 0)
	{
		c[0] = 255;
		c[1] = 250;
		c[2] = 250;
	}
	else if(strcmp(desc, "snow2") == 0)
	{
		c[0] = 238;
		c[1] = 233;
		c[2] = 233;
	}
	else if(strcmp(desc, "snow3") == 0)
	{
		c[0] = 205;
		c[1] = 201;
		c[2] = 201;
	}
	else if(strcmp(desc, "snow4") == 0)
	{
		c[0] = 139;
		c[1] = 137;
		c[2] = 137;
	}
	else if(strcmp(desc, "seashell1") == 0)
	{
		c[0] = 255;
		c[1] = 245;
		c[2] = 238;
	}
	else if(strcmp(desc, "seashell2") == 0)
	{
		c[0] = 238;
		c[1] = 229;
		c[2] = 222;
	}
	else if(strcmp(desc, "seashell3") == 0)
	{
		c[0] = 205;
		c[1] = 197;
		c[2] = 191;
	}
	else if(strcmp(desc, "seashell4") == 0)
	{
		c[0] = 139;
		c[1] = 134;
		c[2] = 130;
	}
	else if(strcmp(desc, "AntiqueWhite1") == 0)
	{
		c[0] = 255;
		c[1] = 239;
		c[2] = 219;
	}
	else if(strcmp(desc, "AntiqueWhite2") == 0)
	{
		c[0] = 238;
		c[1] = 223;
		c[2] = 204;
	}
	else if(strcmp(desc, "AntiqueWhite3") == 0)
	{
		c[0] = 205;
		c[1] = 192;
		c[2] = 176;
	}
	else if(strcmp(desc, "AntiqueWhite4") == 0)
	{
		c[0] = 139;
		c[1] = 131;
		c[2] = 120;
	}
	else if(strcmp(desc, "bisque1") == 0)
	{
		c[0] = 255;
		c[1] = 228;
		c[2] = 196;
	}
	else if(strcmp(desc, "bisque2") == 0)
	{
		c[0] = 238;
		c[1] = 213;
		c[2] = 183;
	}
	else if(strcmp(desc, "bisque3") == 0)
	{
		c[0] = 205;
		c[1] = 183;
		c[2] = 158;
	}
	else if(strcmp(desc, "bisque4") == 0)
	{
		c[0] = 139;
		c[1] = 125;
		c[2] = 107;
	}
	else if(strcmp(desc, "PeachPuff1") == 0)
	{
		c[0] = 255;
		c[1] = 218;
		c[2] = 185;
	}
	else if(strcmp(desc, "PeachPuff2") == 0)
	{
		c[0] = 238;
		c[1] = 203;
		c[2] = 173;
	}
	else if(strcmp(desc, "PeachPuff3") == 0)
	{
		c[0] = 205;
		c[1] = 175;
		c[2] = 149;
	}
	else if(strcmp(desc, "PeachPuff4") == 0)
	{
		c[0] = 139;
		c[1] = 119;
		c[2] = 101;
	}
	else if(strcmp(desc, "NavajoWhite1") == 0)
	{
		c[0] = 255;
		c[1] = 222;
		c[2] = 173;
	}
	else if(strcmp(desc, "NavajoWhite2") == 0)
	{
		c[0] = 238;
		c[1] = 207;
		c[2] = 161;
	}
	else if(strcmp(desc, "NavajoWhite3") == 0)
	{
		c[0] = 205;
		c[1] = 179;
		c[2] = 139;
	}
	else if(strcmp(desc, "NavajoWhite4") == 0)
	{
		c[0] = 139;
		c[1] = 121;
		c[2] = 94;
	}
	else if(strcmp(desc, "LemonChiffon1") == 0)
	{
		c[0] = 255;
		c[1] = 250;
		c[2] = 205;
	}
	else if(strcmp(desc, "LemonChiffon2") == 0)
	{
		c[0] = 238;
		c[1] = 233;
		c[2] = 191;
	}
	else if(strcmp(desc, "LemonChiffon3") == 0)
	{
		c[0] = 205;
		c[1] = 201;
		c[2] = 165;
	}
	else if(strcmp(desc, "LemonChiffon4") == 0)
	{
		c[0] = 139;
		c[1] = 137;
		c[2] = 112;
	}
	else if(strcmp(desc, "cornsilk1") == 0)
	{
		c[0] = 255;
		c[1] = 248;
		c[2] = 220;
	}
	else if(strcmp(desc, "cornsilk2") == 0)
	{
		c[0] = 238;
		c[1] = 232;
		c[2] = 205;
	}
	else if(strcmp(desc, "cornsilk3") == 0)
	{
		c[0] = 205;
		c[1] = 200;
		c[2] = 177;
	}
	else if(strcmp(desc, "cornsilk4") == 0)
	{
		c[0] = 139;
		c[1] = 136;
		c[2] = 120;
	}
	else if(strcmp(desc, "ivory1") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 240;
	}
	else if(strcmp(desc, "ivory2") == 0)
	{
		c[0] = 238;
		c[1] = 238;
		c[2] = 224;
	}
	else if(strcmp(desc, "ivory3") == 0)
	{
		c[0] = 205;
		c[1] = 205;
		c[2] = 193;
	}
	else if(strcmp(desc, "ivory4") == 0)
	{
		c[0] = 139;
		c[1] = 139;
		c[2] = 131;
	}
	else if(strcmp(desc, "honeydew1") == 0)
	{
		c[0] = 240;
		c[1] = 255;
		c[2] = 240;
	}
	else if(strcmp(desc, "honeydew2") == 0)
	{
		c[0] = 224;
		c[1] = 238;
		c[2] = 224;
	}
	else if(strcmp(desc, "honeydew3") == 0)
	{
		c[0] = 193;
		c[1] = 205;
		c[2] = 193;
	}
	else if(strcmp(desc, "honeydew4") == 0)
	{
		c[0] = 131;
		c[1] = 139;
		c[2] = 131;
	}
	else if(strcmp(desc, "LavenderBlush1") == 0)
	{
		c[0] = 255;
		c[1] = 240;
		c[2] = 245;
	}
	else if(strcmp(desc, "LavenderBlush2") == 0)
	{
		c[0] = 238;
		c[1] = 224;
		c[2] = 229;
	}
	else if(strcmp(desc, "LavenderBlush3") == 0)
	{
		c[0] = 205;
		c[1] = 193;
		c[2] = 197;
	}
	else if(strcmp(desc, "LavenderBlush4") == 0)
	{
		c[0] = 139;
		c[1] = 131;
		c[2] = 134;
	}
	else if(strcmp(desc, "MistyRose1") == 0)
	{
		c[0] = 255;
		c[1] = 228;
		c[2] = 225;
	}
	else if(strcmp(desc, "MistyRose2") == 0)
	{
		c[0] = 238;
		c[1] = 213;
		c[2] = 210;
	}
	else if(strcmp(desc, "MistyRose3") == 0)
	{
		c[0] = 205;
		c[1] = 183;
		c[2] = 181;
	}
	else if(strcmp(desc, "MistyRose4") == 0)
	{
		c[0] = 139;
		c[1] = 125;
		c[2] = 123;
	}
	else if(strcmp(desc, "azure1") == 0)
	{
		c[0] = 240;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "azure2") == 0)
	{
		c[0] = 224;
		c[1] = 238;
		c[2] = 238;
	}
	else if(strcmp(desc, "azure3") == 0)
	{
		c[0] = 193;
		c[1] = 205;
		c[2] = 205;
	}
	else if(strcmp(desc, "azure4") == 0)
	{
		c[0] = 131;
		c[1] = 139;
		c[2] = 139;
	}
	else if(strcmp(desc, "SlateBlue1") == 0)
	{
		c[0] = 131;
		c[1] = 111;
		c[2] = 255;
	}
	else if(strcmp(desc, "SlateBlue2") == 0)
	{
		c[0] = 122;
		c[1] = 103;
		c[2] = 238;
	}
	else if(strcmp(desc, "SlateBlue3") == 0)
	{
		c[0] = 105;
		c[1] = 89;
		c[2] = 205;
	}
	else if(strcmp(desc, "SlateBlue4") == 0)
	{
		c[0] = 71;
		c[1] = 60;
		c[2] = 139;
	}
	else if(strcmp(desc, "RoyalBlue1") == 0)
	{
		c[0] = 72;
		c[1] = 118;
		c[2] = 255;
	}
	else if(strcmp(desc, "RoyalBlue2") == 0)
	{
		c[0] = 67;
		c[1] = 110;
		c[2] = 238;
	}
	else if(strcmp(desc, "RoyalBlue3") == 0)
	{
		c[0] = 58;
		c[1] = 95;
		c[2] = 205;
	}
	else if(strcmp(desc, "RoyalBlue4") == 0)
	{
		c[0] = 39;
		c[1] = 64;
		c[2] = 139;
	}
	else if(strcmp(desc, "blue1") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 255;
	}
	else if(strcmp(desc, "blue2") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 238;
	}
	else if(strcmp(desc, "blue3") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 205;
	}
	else if(strcmp(desc, "blue4") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 139;
	}
	else if(strcmp(desc, "DodgerBlue1") == 0)
	{
		c[0] = 30;
		c[1] = 144;
		c[2] = 255;
	}
	else if(strcmp(desc, "DodgerBlue2") == 0)
	{
		c[0] = 28;
		c[1] = 134;
		c[2] = 238;
	}
	else if(strcmp(desc, "DodgerBlue3") == 0)
	{
		c[0] = 24;
		c[1] = 116;
		c[2] = 205;
	}
	else if(strcmp(desc, "DodgerBlue4") == 0)
	{
		c[0] = 16;
		c[1] = 78;
		c[2] = 139;
	}
	else if(strcmp(desc, "SteelBlue1") == 0)
	{
		c[0] = 99;
		c[1] = 184;
		c[2] = 255;
	}
	else if(strcmp(desc, "SteelBlue2") == 0)
	{
		c[0] = 92;
		c[1] = 172;
		c[2] = 238;
	}
	else if(strcmp(desc, "SteelBlue3") == 0)
	{
		c[0] = 79;
		c[1] = 148;
		c[2] = 205;
	}
	else if(strcmp(desc, "SteelBlue4") == 0)
	{
		c[0] = 54;
		c[1] = 100;
		c[2] = 139;
	}
	else if(strcmp(desc, "DeepSkyBlue1") == 0)
	{
		c[0] = 0;
		c[1] = 191;
		c[2] = 255;
	}
	else if(strcmp(desc, "DeepSkyBlue2") == 0)
	{
		c[0] = 0;
		c[1] = 178;
		c[2] = 238;
	}
	else if(strcmp(desc, "DeepSkyBlue3") == 0)
	{
		c[0] = 0;
		c[1] = 154;
		c[2] = 205;
	}
	else if(strcmp(desc, "DeepSkyBlue4") == 0)
	{
		c[0] = 0;
		c[1] = 104;
		c[2] = 139;
	}
	else if(strcmp(desc, "SkyBlue1") == 0)
	{
		c[0] = 135;
		c[1] = 206;
		c[2] = 255;
	}
	else if(strcmp(desc, "SkyBlue2") == 0)
	{
		c[0] = 126;
		c[1] = 192;
		c[2] = 238;
	}
	else if(strcmp(desc, "SkyBlue3") == 0)
	{
		c[0] = 108;
		c[1] = 166;
		c[2] = 205;
	}
	else if(strcmp(desc, "SkyBlue4") == 0)
	{
		c[0] = 74;
		c[1] = 112;
		c[2] = 139;
	}
	else if(strcmp(desc, "LightSkyBlue1") == 0)
	{
		c[0] = 176;
		c[1] = 226;
		c[2] = 255;
	}
	else if(strcmp(desc, "LightSkyBlue2") == 0)
	{
		c[0] = 164;
		c[1] = 211;
		c[2] = 238;
	}
	else if(strcmp(desc, "LightSkyBlue3") == 0)
	{
		c[0] = 141;
		c[1] = 182;
		c[2] = 205;
	}
	else if(strcmp(desc, "LightSkyBlue4") == 0)
	{
		c[0] = 96;
		c[1] = 123;
		c[2] = 139;
	}
	else if(strcmp(desc, "SlateGray1") == 0)
	{
		c[0] = 198;
		c[1] = 226;
		c[2] = 255;
	}
	else if(strcmp(desc, "SlateGray2") == 0)
	{
		c[0] = 185;
		c[1] = 211;
		c[2] = 238;
	}
	else if(strcmp(desc, "SlateGray3") == 0)
	{
		c[0] = 159;
		c[1] = 182;
		c[2] = 205;
	}
	else if(strcmp(desc, "SlateGray4") == 0)
	{
		c[0] = 108;
		c[1] = 123;
		c[2] = 139;
	}
	else if(strcmp(desc, "LightSteelBlue1") == 0)
	{
		c[0] = 202;
		c[1] = 225;
		c[2] = 255;
	}
	else if(strcmp(desc, "LightSteelBlue2") == 0)
	{
		c[0] = 188;
		c[1] = 210;
		c[2] = 238;
	}
	else if(strcmp(desc, "LightSteelBlue3") == 0)
	{
		c[0] = 162;
		c[1] = 181;
		c[2] = 205;
	}
	else if(strcmp(desc, "LightSteelBlue4") == 0)
	{
		c[0] = 110;
		c[1] = 123;
		c[2] = 139;
	}
	else if(strcmp(desc, "LightBlue1") == 0)
	{
		c[0] = 191;
		c[1] = 239;
		c[2] = 255;
	}
	else if(strcmp(desc, "LightBlue2") == 0)
	{
		c[0] = 178;
		c[1] = 223;
		c[2] = 238;
	}
	else if(strcmp(desc, "LightBlue3") == 0)
	{
		c[0] = 154;
		c[1] = 192;
		c[2] = 205;
	}
	else if(strcmp(desc, "LightBlue4") == 0)
	{
		c[0] = 104;
		c[1] = 131;
		c[2] = 139;
	}
	else if(strcmp(desc, "LightCyan1") == 0)
	{
		c[0] = 224;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "LightCyan2") == 0)
	{
		c[0] = 209;
		c[1] = 238;
		c[2] = 238;
	}
	else if(strcmp(desc, "LightCyan3") == 0)
	{
		c[0] = 180;
		c[1] = 205;
		c[2] = 205;
	}
	else if(strcmp(desc, "LightCyan4") == 0)
	{
		c[0] = 122;
		c[1] = 139;
		c[2] = 139;
	}
	else if(strcmp(desc, "PaleTurquoise1") == 0)
	{
		c[0] = 187;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "PaleTurquoise2") == 0)
	{
		c[0] = 174;
		c[1] = 238;
		c[2] = 238;
	}
	else if(strcmp(desc, "PaleTurquoise3") == 0)
	{
		c[0] = 150;
		c[1] = 205;
		c[2] = 205;
	}
	else if(strcmp(desc, "PaleTurquoise4") == 0)
	{
		c[0] = 102;
		c[1] = 139;
		c[2] = 139;
	}
	else if(strcmp(desc, "CadetBlue1") == 0)
	{
		c[0] = 152;
		c[1] = 245;
		c[2] = 255;
	}
	else if(strcmp(desc, "CadetBlue2") == 0)
	{
		c[0] = 142;
		c[1] = 229;
		c[2] = 238;
	}
	else if(strcmp(desc, "CadetBlue3") == 0)
	{
		c[0] = 122;
		c[1] = 197;
		c[2] = 205;
	}
	else if(strcmp(desc, "CadetBlue4") == 0)
	{
		c[0] = 83;
		c[1] = 134;
		c[2] = 139;
	}
	else if(strcmp(desc, "turquoise1") == 0)
	{
		c[0] = 0;
		c[1] = 245;
		c[2] = 255;
	}
	else if(strcmp(desc, "turquoise2") == 0)
	{
		c[0] = 0;
		c[1] = 229;
		c[2] = 238;
	}
	else if(strcmp(desc, "turquoise3") == 0)
	{
		c[0] = 0;
		c[1] = 197;
		c[2] = 205;
	}
	else if(strcmp(desc, "turquoise4") == 0)
	{
		c[0] = 0;
		c[1] = 134;
		c[2] = 139;
	}
	else if(strcmp(desc, "cyan1") == 0)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "cyan2") == 0)
	{
		c[0] = 0;
		c[1] = 238;
		c[2] = 238;
	}
	else if(strcmp(desc, "cyan3") == 0)
	{
		c[0] = 0;
		c[1] = 205;
		c[2] = 205;
	}
	else if(strcmp(desc, "cyan4") == 0)
	{
		c[0] = 0;
		c[1] = 139;
		c[2] = 139;
	}
	else if(strcmp(desc, "DarkSlateGray1") == 0)
	{
		c[0] = 151;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "DarkSlateGray2") == 0)
	{
		c[0] = 141;
		c[1] = 238;
		c[2] = 238;
	}
	else if(strcmp(desc, "DarkSlateGray3") == 0)
	{
		c[0] = 121;
		c[1] = 205;
		c[2] = 205;
	}
	else if(strcmp(desc, "DarkSlateGray4") == 0)
	{
		c[0] = 82;
		c[1] = 139;
		c[2] = 139;
	}
	else if(strcmp(desc, "aquamarine1") == 0)
	{
		c[0] = 127;
		c[1] = 255;
		c[2] = 212;
	}
	else if(strcmp(desc, "aquamarine2") == 0)
	{
		c[0] = 118;
		c[1] = 238;
		c[2] = 198;
	}
	else if(strcmp(desc, "aquamarine3") == 0)
	{
		c[0] = 102;
		c[1] = 205;
		c[2] = 170;
	}
	else if(strcmp(desc, "aquamarine4") == 0)
	{
		c[0] = 69;
		c[1] = 139;
		c[2] = 116;
	}
	else if(strcmp(desc, "DarkSeaGreen1") == 0)
	{
		c[0] = 193;
		c[1] = 255;
		c[2] = 193;
	}
	else if(strcmp(desc, "DarkSeaGreen2") == 0)
	{
		c[0] = 180;
		c[1] = 238;
		c[2] = 180;
	}
	else if(strcmp(desc, "DarkSeaGreen3") == 0)
	{
		c[0] = 155;
		c[1] = 205;
		c[2] = 155;
	}
	else if(strcmp(desc, "DarkSeaGreen4") == 0)
	{
		c[0] = 105;
		c[1] = 139;
		c[2] = 105;
	}
	else if(strcmp(desc, "SeaGreen1") == 0)
	{
		c[0] = 84;
		c[1] = 255;
		c[2] = 159;
	}
	else if(strcmp(desc, "SeaGreen2") == 0)
	{
		c[0] = 78;
		c[1] = 238;
		c[2] = 148;
	}
	else if(strcmp(desc, "SeaGreen3") == 0)
	{
		c[0] = 67;
		c[1] = 205;
		c[2] = 128;
	}
	else if(strcmp(desc, "SeaGreen4") == 0)
	{
		c[0] = 46;
		c[1] = 139;
		c[2] = 87;
	}
	else if(strcmp(desc, "PaleGreen1") == 0)
	{
		c[0] = 154;
		c[1] = 255;
		c[2] = 154;
	}
	else if(strcmp(desc, "PaleGreen2") == 0)
	{
		c[0] = 144;
		c[1] = 238;
		c[2] = 144;
	}
	else if(strcmp(desc, "PaleGreen3") == 0)
	{
		c[0] = 124;
		c[1] = 205;
		c[2] = 124;
	}
	else if(strcmp(desc, "PaleGreen4") == 0)
	{
		c[0] = 84;
		c[1] = 139;
		c[2] = 84;
	}
	else if(strcmp(desc, "SpringGreen1") == 0)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = 127;
	}
	else if(strcmp(desc, "SpringGreen2") == 0)
	{
		c[0] = 0;
		c[1] = 238;
		c[2] = 118;
	}
	else if(strcmp(desc, "SpringGreen3") == 0)
	{
		c[0] = 0;
		c[1] = 205;
		c[2] = 102;
	}
	else if(strcmp(desc, "SpringGreen4") == 0)
	{
		c[0] = 0;
		c[1] = 139;
		c[2] = 69;
	}
	else if(strcmp(desc, "green1") == 0)
	{
		c[0] = 0;
		c[1] = 255;
		c[2] = 0;
	}
	else if(strcmp(desc, "green2") == 0)
	{
		c[0] = 0;
		c[1] = 238;
		c[2] = 0;
	}
	else if(strcmp(desc, "green3") == 0)
	{
		c[0] = 0;
		c[1] = 205;
		c[2] = 0;
	}
	else if(strcmp(desc, "green4") == 0)
	{
		c[0] = 0;
		c[1] = 139;
		c[2] = 0;
	}
	else if(strcmp(desc, "chartreuse1") == 0)
	{
		c[0] = 127;
		c[1] = 255;
		c[2] = 0;
	}
	else if(strcmp(desc, "chartreuse2") == 0)
	{
		c[0] = 118;
		c[1] = 238;
		c[2] = 0;
	}
	else if(strcmp(desc, "chartreuse3") == 0)
	{
		c[0] = 102;
		c[1] = 205;
		c[2] = 0;
	}
	else if(strcmp(desc, "chartreuse4") == 0)
	{
		c[0] = 69;
		c[1] = 139;
		c[2] = 0;
	}
	else if(strcmp(desc, "OliveDrab1") == 0)
	{
		c[0] = 192;
		c[1] = 255;
		c[2] = 62;
	}
	else if(strcmp(desc, "OliveDrab2") == 0)
	{
		c[0] = 179;
		c[1] = 238;
		c[2] = 58;
	}
	else if(strcmp(desc, "OliveDrab3") == 0)
	{
		c[0] = 154;
		c[1] = 205;
		c[2] = 50;
	}
	else if(strcmp(desc, "OliveDrab4") == 0)
	{
		c[0] = 105;
		c[1] = 139;
		c[2] = 34;
	}
	else if(strcmp(desc, "DarkOliveGreen1") == 0)
	{
		c[0] = 202;
		c[1] = 255;
		c[2] = 112;
	}
	else if(strcmp(desc, "DarkOliveGreen2") == 0)
	{
		c[0] = 188;
		c[1] = 238;
		c[2] = 104;
	}
	else if(strcmp(desc, "DarkOliveGreen3") == 0)
	{
		c[0] = 162;
		c[1] = 205;
		c[2] = 90;
	}
	else if(strcmp(desc, "DarkOliveGreen4") == 0)
	{
		c[0] = 110;
		c[1] = 139;
		c[2] = 61;
	}
	else if(strcmp(desc, "khaki1") == 0)
	{
		c[0] = 255;
		c[1] = 246;
		c[2] = 143;
	}
	else if(strcmp(desc, "khaki2") == 0)
	{
		c[0] = 238;
		c[1] = 230;
		c[2] = 133;
	}
	else if(strcmp(desc, "khaki3") == 0)
	{
		c[0] = 205;
		c[1] = 198;
		c[2] = 115;
	}
	else if(strcmp(desc, "khaki4") == 0)
	{
		c[0] = 139;
		c[1] = 134;
		c[2] = 78;
	}
	else if(strcmp(desc, "LightGoldenrod1") == 0)
	{
		c[0] = 255;
		c[1] = 236;
		c[2] = 139;
	}
	else if(strcmp(desc, "LightGoldenrod2") == 0)
	{
		c[0] = 238;
		c[1] = 220;
		c[2] = 130;
	}
	else if(strcmp(desc, "LightGoldenrod3") == 0)
	{
		c[0] = 205;
		c[1] = 190;
		c[2] = 112;
	}
	else if(strcmp(desc, "LightGoldenrod4") == 0)
	{
		c[0] = 139;
		c[1] = 129;
		c[2] = 76;
	}
	else if(strcmp(desc, "LightYellow1") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 224;
	}
	else if(strcmp(desc, "LightYellow2") == 0)
	{
		c[0] = 238;
		c[1] = 238;
		c[2] = 209;
	}
	else if(strcmp(desc, "LightYellow3") == 0)
	{
		c[0] = 205;
		c[1] = 205;
		c[2] = 180;
	}
	else if(strcmp(desc, "LightYellow4") == 0)
	{
		c[0] = 139;
		c[1] = 139;
		c[2] = 122;
	}
	else if(strcmp(desc, "yellow1") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 0;
	}
	else if(strcmp(desc, "yellow2") == 0)
	{
		c[0] = 238;
		c[1] = 238;
		c[2] = 0;
	}
	else if(strcmp(desc, "yellow3") == 0)
	{
		c[0] = 205;
		c[1] = 205;
		c[2] = 0;
	}
	else if(strcmp(desc, "yellow4") == 0)
	{
		c[0] = 139;
		c[1] = 139;
		c[2] = 0;
	}
	else if(strcmp(desc, "gold1") == 0)
	{
		c[0] = 255;
		c[1] = 215;
		c[2] = 0;
	}
	else if(strcmp(desc, "gold2") == 0)
	{
		c[0] = 238;
		c[1] = 201;
		c[2] = 0;
	}
	else if(strcmp(desc, "gold3") == 0)
	{
		c[0] = 205;
		c[1] = 173;
		c[2] = 0;
	}
	else if(strcmp(desc, "gold4") == 0)
	{
		c[0] = 139;
		c[1] = 117;
		c[2] = 0;
	}
	else if(strcmp(desc, "goldenrod1") == 0)
	{
		c[0] = 255;
		c[1] = 193;
		c[2] = 37;
	}
	else if(strcmp(desc, "goldenrod2") == 0)
	{
		c[0] = 238;
		c[1] = 180;
		c[2] = 34;
	}
	else if(strcmp(desc, "goldenrod3") == 0)
	{
		c[0] = 205;
		c[1] = 155;
		c[2] = 29;
	}
	else if(strcmp(desc, "goldenrod4") == 0)
	{
		c[0] = 139;
		c[1] = 105;
		c[2] = 20;
	}
	else if(strcmp(desc, "DarkGoldenrod1") == 0)
	{
		c[0] = 255;
		c[1] = 185;
		c[2] = 15;
	}
	else if(strcmp(desc, "DarkGoldenrod2") == 0)
	{
		c[0] = 238;
		c[1] = 173;
		c[2] = 14;
	}
	else if(strcmp(desc, "DarkGoldenrod3") == 0)
	{
		c[0] = 205;
		c[1] = 149;
		c[2] = 12;
	}
	else if(strcmp(desc, "DarkGoldenrod4") == 0)
	{
		c[0] = 139;
		c[1] = 101;
		c[2] = 8;
	}
	else if(strcmp(desc, "RosyBrown1") == 0)
	{
		c[0] = 255;
		c[1] = 193;
		c[2] = 193;
	}
	else if(strcmp(desc, "RosyBrown2") == 0)
	{
		c[0] = 238;
		c[1] = 180;
		c[2] = 180;
	}
	else if(strcmp(desc, "RosyBrown3") == 0)
	{
		c[0] = 205;
		c[1] = 155;
		c[2] = 155;
	}
	else if(strcmp(desc, "RosyBrown4") == 0)
	{
		c[0] = 139;
		c[1] = 105;
		c[2] = 105;
	}
	else if(strcmp(desc, "IndianRed1") == 0)
	{
		c[0] = 255;
		c[1] = 106;
		c[2] = 106;
	}
	else if(strcmp(desc, "IndianRed2") == 0)
	{
		c[0] = 238;
		c[1] = 99;
		c[2] = 99;
	}
	else if(strcmp(desc, "IndianRed3") == 0)
	{
		c[0] = 205;
		c[1] = 85;
		c[2] = 85;
	}
	else if(strcmp(desc, "IndianRed4") == 0)
	{
		c[0] = 139;
		c[1] = 58;
		c[2] = 58;
	}
	else if(strcmp(desc, "sienna1") == 0)
	{
		c[0] = 255;
		c[1] = 130;
		c[2] = 71;
	}
	else if(strcmp(desc, "sienna2") == 0)
	{
		c[0] = 238;
		c[1] = 121;
		c[2] = 66;
	}
	else if(strcmp(desc, "sienna3") == 0)
	{
		c[0] = 205;
		c[1] = 104;
		c[2] = 57;
	}
	else if(strcmp(desc, "sienna4") == 0)
	{
		c[0] = 139;
		c[1] = 71;
		c[2] = 38;
	}
	else if(strcmp(desc, "burlywood1") == 0)
	{
		c[0] = 255;
		c[1] = 211;
		c[2] = 155;
	}
	else if(strcmp(desc, "burlywood2") == 0)
	{
		c[0] = 238;
		c[1] = 197;
		c[2] = 145;
	}
	else if(strcmp(desc, "burlywood3") == 0)
	{
		c[0] = 205;
		c[1] = 170;
		c[2] = 125;
	}
	else if(strcmp(desc, "burlywood4") == 0)
	{
		c[0] = 139;
		c[1] = 115;
		c[2] = 85;
	}
	else if(strcmp(desc, "wheat1") == 0)
	{
		c[0] = 255;
		c[1] = 231;
		c[2] = 186;
	}
	else if(strcmp(desc, "wheat2") == 0)
	{
		c[0] = 238;
		c[1] = 216;
		c[2] = 174;
	}
	else if(strcmp(desc, "wheat3") == 0)
	{
		c[0] = 205;
		c[1] = 186;
		c[2] = 150;
	}
	else if(strcmp(desc, "wheat4") == 0)
	{
		c[0] = 139;
		c[1] = 126;
		c[2] = 102;
	}
	else if(strcmp(desc, "tan1") == 0)
	{
		c[0] = 255;
		c[1] = 165;
		c[2] = 79;
	}
	else if(strcmp(desc, "tan2") == 0)
	{
		c[0] = 238;
		c[1] = 154;
		c[2] = 73;
	}
	else if(strcmp(desc, "tan3") == 0)
	{
		c[0] = 205;
		c[1] = 133;
		c[2] = 63;
	}
	else if(strcmp(desc, "tan4") == 0)
	{
		c[0] = 139;
		c[1] = 90;
		c[2] = 43;
	}
	else if(strcmp(desc, "chocolate1") == 0)
	{
		c[0] = 255;
		c[1] = 127;
		c[2] = 36;
	}
	else if(strcmp(desc, "chocolate2") == 0)
	{
		c[0] = 238;
		c[1] = 118;
		c[2] = 33;
	}
	else if(strcmp(desc, "chocolate3") == 0)
	{
		c[0] = 205;
		c[1] = 102;
		c[2] = 29;
	}
	else if(strcmp(desc, "chocolate4") == 0)
	{
		c[0] = 139;
		c[1] = 69;
		c[2] = 19;
	}
	else if(strcmp(desc, "firebrick1") == 0)
	{
		c[0] = 255;
		c[1] = 48;
		c[2] = 48;
	}
	else if(strcmp(desc, "firebrick2") == 0)
	{
		c[0] = 238;
		c[1] = 44;
		c[2] = 44;
	}
	else if(strcmp(desc, "firebrick3") == 0)
	{
		c[0] = 205;
		c[1] = 38;
		c[2] = 38;
	}
	else if(strcmp(desc, "firebrick4") == 0)
	{
		c[0] = 139;
		c[1] = 26;
		c[2] = 26;
	}
	else if(strcmp(desc, "brown1") == 0)
	{
		c[0] = 255;
		c[1] = 64;
		c[2] = 64;
	}
	else if(strcmp(desc, "brown2") == 0)
	{
		c[0] = 238;
		c[1] = 59;
		c[2] = 59;
	}
	else if(strcmp(desc, "brown3") == 0)
	{
		c[0] = 205;
		c[1] = 51;
		c[2] = 51;
	}
	else if(strcmp(desc, "brown4") == 0)
	{
		c[0] = 139;
		c[1] = 35;
		c[2] = 35;
	}
	else if(strcmp(desc, "salmon1") == 0)
	{
		c[0] = 255;
		c[1] = 140;
		c[2] = 105;
	}
	else if(strcmp(desc, "salmon2") == 0)
	{
		c[0] = 238;
		c[1] = 130;
		c[2] = 98;
	}
	else if(strcmp(desc, "salmon3") == 0)
	{
		c[0] = 205;
		c[1] = 112;
		c[2] = 84;
	}
	else if(strcmp(desc, "salmon4") == 0)
	{
		c[0] = 139;
		c[1] = 76;
		c[2] = 57;
	}
	else if(strcmp(desc, "LightSalmon1") == 0)
	{
		c[0] = 255;
		c[1] = 160;
		c[2] = 122;
	}
	else if(strcmp(desc, "LightSalmon2") == 0)
	{
		c[0] = 238;
		c[1] = 149;
		c[2] = 114;
	}
	else if(strcmp(desc, "LightSalmon3") == 0)
	{
		c[0] = 205;
		c[1] = 129;
		c[2] = 98;
	}
	else if(strcmp(desc, "LightSalmon4") == 0)
	{
		c[0] = 139;
		c[1] = 87;
		c[2] = 66;
	}
	else if(strcmp(desc, "orange1") == 0)
	{
		c[0] = 255;
		c[1] = 165;
		c[2] = 0;
	}
	else if(strcmp(desc, "orange2") == 0)
	{
		c[0] = 238;
		c[1] = 154;
		c[2] = 0;
	}
	else if(strcmp(desc, "orange3") == 0)
	{
		c[0] = 205;
		c[1] = 133;
		c[2] = 0;
	}
	else if(strcmp(desc, "orange4") == 0)
	{
		c[0] = 139;
		c[1] = 90;
		c[2] = 0;
	}
	else if(strcmp(desc, "DarkOrange1") == 0)
	{
		c[0] = 255;
		c[1] = 127;
		c[2] = 0;
	}
	else if(strcmp(desc, "DarkOrange2") == 0)
	{
		c[0] = 238;
		c[1] = 118;
		c[2] = 0;
	}
	else if(strcmp(desc, "DarkOrange3") == 0)
	{
		c[0] = 205;
		c[1] = 102;
		c[2] = 0;
	}
	else if(strcmp(desc, "DarkOrange4") == 0)
	{
		c[0] = 139;
		c[1] = 69;
		c[2] = 0;
	}
	else if(strcmp(desc, "coral1") == 0)
	{
		c[0] = 255;
		c[1] = 114;
		c[2] = 86;
	}
	else if(strcmp(desc, "coral2") == 0)
	{
		c[0] = 238;
		c[1] = 106;
		c[2] = 80;
	}
	else if(strcmp(desc, "coral3") == 0)
	{
		c[0] = 205;
		c[1] = 91;
		c[2] = 69;
	}
	else if(strcmp(desc, "coral4") == 0)
	{
		c[0] = 139;
		c[1] = 62;
		c[2] = 47;
	}
	else if(strcmp(desc, "tomato1") == 0)
	{
		c[0] = 255;
		c[1] = 99;
		c[2] = 71;
	}
	else if(strcmp(desc, "tomato2") == 0)
	{
		c[0] = 238;
		c[1] = 92;
		c[2] = 66;
	}
	else if(strcmp(desc, "tomato3") == 0)
	{
		c[0] = 205;
		c[1] = 79;
		c[2] = 57;
	}
	else if(strcmp(desc, "tomato4") == 0)
	{
		c[0] = 139;
		c[1] = 54;
		c[2] = 38;
	}
	else if(strcmp(desc, "OrangeRed1") == 0)
	{
		c[0] = 255;
		c[1] = 69;
		c[2] = 0;
	}
	else if(strcmp(desc, "OrangeRed2") == 0)
	{
		c[0] = 238;
		c[1] = 64;
		c[2] = 0;
	}
	else if(strcmp(desc, "OrangeRed3") == 0)
	{
		c[0] = 205;
		c[1] = 55;
		c[2] = 0;
	}
	else if(strcmp(desc, "OrangeRed4") == 0)
	{
		c[0] = 139;
		c[1] = 37;
		c[2] = 0;
	}
	else if(strcmp(desc, "red1") == 0)
	{
		c[0] = 255;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "red2") == 0)
	{
		c[0] = 238;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "red3") == 0)
	{
		c[0] = 205;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "red4") == 0)
	{
		c[0] = 139;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "DeepPink1") == 0)
	{
		c[0] = 255;
		c[1] = 20;
		c[2] = 147;
	}
	else if(strcmp(desc, "DeepPink2") == 0)
	{
		c[0] = 238;
		c[1] = 18;
		c[2] = 137;
	}
	else if(strcmp(desc, "DeepPink3") == 0)
	{
		c[0] = 205;
		c[1] = 16;
		c[2] = 118;
	}
	else if(strcmp(desc, "DeepPink4") == 0)
	{
		c[0] = 139;
		c[1] = 10;
		c[2] = 80;
	}
	else if(strcmp(desc, "HotPink1") == 0)
	{
		c[0] = 255;
		c[1] = 110;
		c[2] = 180;
	}
	else if(strcmp(desc, "HotPink2") == 0)
	{
		c[0] = 238;
		c[1] = 106;
		c[2] = 167;
	}
	else if(strcmp(desc, "HotPink3") == 0)
	{
		c[0] = 205;
		c[1] = 96;
		c[2] = 144;
	}
	else if(strcmp(desc, "HotPink4") == 0)
	{
		c[0] = 139;
		c[1] = 58;
		c[2] = 98;
	}
	else if(strcmp(desc, "pink1") == 0)
	{
		c[0] = 255;
		c[1] = 181;
		c[2] = 197;
	}
	else if(strcmp(desc, "pink2") == 0)
	{
		c[0] = 238;
		c[1] = 169;
		c[2] = 184;
	}
	else if(strcmp(desc, "pink3") == 0)
	{
		c[0] = 205;
		c[1] = 145;
		c[2] = 158;
	}
	else if(strcmp(desc, "pink4") == 0)
	{
		c[0] = 139;
		c[1] = 99;
		c[2] = 108;
	}
	else if(strcmp(desc, "LightPink1") == 0)
	{
		c[0] = 255;
		c[1] = 174;
		c[2] = 185;
	}
	else if(strcmp(desc, "LightPink2") == 0)
	{
		c[0] = 238;
		c[1] = 162;
		c[2] = 173;
	}
	else if(strcmp(desc, "LightPink3") == 0)
	{
		c[0] = 205;
		c[1] = 140;
		c[2] = 149;
	}
	else if(strcmp(desc, "LightPink4") == 0)
	{
		c[0] = 139;
		c[1] = 95;
		c[2] = 101;
	}
	else if(strcmp(desc, "PaleVioletRed1") == 0)
	{
		c[0] = 255;
		c[1] = 130;
		c[2] = 171;
	}
	else if(strcmp(desc, "PaleVioletRed2") == 0)
	{
		c[0] = 238;
		c[1] = 121;
		c[2] = 159;
	}
	else if(strcmp(desc, "PaleVioletRed3") == 0)
	{
		c[0] = 205;
		c[1] = 104;
		c[2] = 137;
	}
	else if(strcmp(desc, "PaleVioletRed4") == 0)
	{
		c[0] = 139;
		c[1] = 71;
		c[2] = 93;
	}
	else if(strcmp(desc, "maroon1") == 0)
	{
		c[0] = 255;
		c[1] = 52;
		c[2] = 179;
	}
	else if(strcmp(desc, "maroon2") == 0)
	{
		c[0] = 238;
		c[1] = 48;
		c[2] = 167;
	}
	else if(strcmp(desc, "maroon3") == 0)
	{
		c[0] = 205;
		c[1] = 41;
		c[2] = 144;
	}
	else if(strcmp(desc, "maroon4") == 0)
	{
		c[0] = 139;
		c[1] = 28;
		c[2] = 98;
	}
	else if(strcmp(desc, "VioletRed1") == 0)
	{
		c[0] = 255;
		c[1] = 62;
		c[2] = 150;
	}
	else if(strcmp(desc, "VioletRed2") == 0)
	{
		c[0] = 238;
		c[1] = 58;
		c[2] = 140;
	}
	else if(strcmp(desc, "VioletRed3") == 0)
	{
		c[0] = 205;
		c[1] = 50;
		c[2] = 120;
	}
	else if(strcmp(desc, "VioletRed4") == 0)
	{
		c[0] = 139;
		c[1] = 34;
		c[2] = 82;
	}
	else if(strcmp(desc, "magenta1") == 0)
	{
		c[0] = 255;
		c[1] = 0;
		c[2] = 255;
	}
	else if(strcmp(desc, "magenta2") == 0)
	{
		c[0] = 238;
		c[1] = 0;
		c[2] = 238;
	}
	else if(strcmp(desc, "magenta3") == 0)
	{
		c[0] = 205;
		c[1] = 0;
		c[2] = 205;
	}
	else if(strcmp(desc, "magenta4") == 0)
	{
		c[0] = 139;
		c[1] = 0;
		c[2] = 139;
	}
	else if(strcmp(desc, "orchid1") == 0)
	{
		c[0] = 255;
		c[1] = 131;
		c[2] = 250;
	}
	else if(strcmp(desc, "orchid2") == 0)
	{
		c[0] = 238;
		c[1] = 122;
		c[2] = 233;
	}
	else if(strcmp(desc, "orchid3") == 0)
	{
		c[0] = 205;
		c[1] = 105;
		c[2] = 201;
	}
	else if(strcmp(desc, "orchid4") == 0)
	{
		c[0] = 139;
		c[1] = 71;
		c[2] = 137;
	}
	else if(strcmp(desc, "plum1") == 0)
	{
		c[0] = 255;
		c[1] = 187;
		c[2] = 255;
	}
	else if(strcmp(desc, "plum2") == 0)
	{
		c[0] = 238;
		c[1] = 174;
		c[2] = 238;
	}
	else if(strcmp(desc, "plum3") == 0)
	{
		c[0] = 205;
		c[1] = 150;
		c[2] = 205;
	}
	else if(strcmp(desc, "plum4") == 0)
	{
		c[0] = 139;
		c[1] = 102;
		c[2] = 139;
	}
	else if(strcmp(desc, "MediumOrchid1") == 0)
	{
		c[0] = 224;
		c[1] = 102;
		c[2] = 255;
	}
	else if(strcmp(desc, "MediumOrchid2") == 0)
	{
		c[0] = 209;
		c[1] = 95;
		c[2] = 238;
	}
	else if(strcmp(desc, "MediumOrchid3") == 0)
	{
		c[0] = 180;
		c[1] = 82;
		c[2] = 205;
	}
	else if(strcmp(desc, "MediumOrchid4") == 0)
	{
		c[0] = 122;
		c[1] = 55;
		c[2] = 139;
	}
	else if(strcmp(desc, "DarkOrchid1") == 0)
	{
		c[0] = 191;
		c[1] = 62;
		c[2] = 255;
	}
	else if(strcmp(desc, "DarkOrchid2") == 0)
	{
		c[0] = 178;
		c[1] = 58;
		c[2] = 238;
	}
	else if(strcmp(desc, "DarkOrchid3") == 0)
	{
		c[0] = 154;
		c[1] = 50;
		c[2] = 205;
	}
	else if(strcmp(desc, "DarkOrchid4") == 0)
	{
		c[0] = 104;
		c[1] = 34;
		c[2] = 139;
	}
	else if(strcmp(desc, "purple1") == 0)
	{
		c[0] = 155;
		c[1] = 48;
		c[2] = 255;
	}
	else if(strcmp(desc, "purple2") == 0)
	{
		c[0] = 145;
		c[1] = 44;
		c[2] = 238;
	}
	else if(strcmp(desc, "purple3") == 0)
	{
		c[0] = 125;
		c[1] = 38;
		c[2] = 205;
	}
	else if(strcmp(desc, "purple4") == 0)
	{
		c[0] = 85;
		c[1] = 26;
		c[2] = 139;
	}
	else if(strcmp(desc, "MediumPurple1") == 0)
	{
		c[0] = 171;
		c[1] = 130;
		c[2] = 255;
	}
	else if(strcmp(desc, "MediumPurple2") == 0)
	{
		c[0] = 159;
		c[1] = 121;
		c[2] = 238;
	}
	else if(strcmp(desc, "MediumPurple3") == 0)
	{
		c[0] = 137;
		c[1] = 104;
		c[2] = 205;
	}
	else if(strcmp(desc, "MediumPurple4") == 0)
	{
		c[0] = 93;
		c[1] = 71;
		c[2] = 139;
	}
	else if(strcmp(desc, "thistle1") == 0)
	{
		c[0] = 255;
		c[1] = 225;
		c[2] = 255;
	}
	else if(strcmp(desc, "thistle2") == 0)
	{
		c[0] = 238;
		c[1] = 210;
		c[2] = 238;
	}
	else if(strcmp(desc, "thistle3") == 0)
	{
		c[0] = 205;
		c[1] = 181;
		c[2] = 205;
	}
	else if(strcmp(desc, "thistle4") == 0)
	{
		c[0] = 139;
		c[1] = 123;
		c[2] = 139;
	}
	else if(strcmp(desc, "gray0") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "grey0") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "gray1") == 0)
	{
		c[0] = 3;
		c[1] = 3;
		c[2] = 3;
	}
	else if(strcmp(desc, "grey1") == 0)
	{
		c[0] = 3;
		c[1] = 3;
		c[2] = 3;
	}
	else if(strcmp(desc, "gray2") == 0)
	{
		c[0] = 5;
		c[1] = 5;
		c[2] = 5;
	}
	else if(strcmp(desc, "grey2") == 0)
	{
		c[0] = 5;
		c[1] = 5;
		c[2] = 5;
	}
	else if(strcmp(desc, "gray3") == 0)
	{
		c[0] = 8;
		c[1] = 8;
		c[2] = 8;
	}
	else if(strcmp(desc, "grey3") == 0)
	{
		c[0] = 8;
		c[1] = 8;
		c[2] = 8;
	}
	else if(strcmp(desc, "gray4") == 0)
	{
		c[0] = 10;
		c[1] = 10;
		c[2] = 10;
	}
	else if(strcmp(desc, "grey4") == 0)
	{
		c[0] = 10;
		c[1] = 10;
		c[2] = 10;
	}
	else if(strcmp(desc, "gray5") == 0)
	{
		c[0] = 13;
		c[1] = 13;
		c[2] = 13;
	}
	else if(strcmp(desc, "grey5") == 0)
	{
		c[0] = 13;
		c[1] = 13;
		c[2] = 13;
	}
	else if(strcmp(desc, "gray6") == 0)
	{
		c[0] = 15;
		c[1] = 15;
		c[2] = 15;
	}
	else if(strcmp(desc, "grey6") == 0)
	{
		c[0] = 15;
		c[1] = 15;
		c[2] = 15;
	}
	else if(strcmp(desc, "gray7") == 0)
	{
		c[0] = 18;
		c[1] = 18;
		c[2] = 18;
	}
	else if(strcmp(desc, "grey7") == 0)
	{
		c[0] = 18;
		c[1] = 18;
		c[2] = 18;
	}
	else if(strcmp(desc, "gray8") == 0)
	{
		c[0] = 20;
		c[1] = 20;
		c[2] = 20;
	}
	else if(strcmp(desc, "grey8") == 0)
	{
		c[0] = 20;
		c[1] = 20;
		c[2] = 20;
	}
	else if(strcmp(desc, "gray9") == 0)
	{
		c[0] = 23;
		c[1] = 23;
		c[2] = 23;
	}
	else if(strcmp(desc, "grey9") == 0)
	{
		c[0] = 23;
		c[1] = 23;
		c[2] = 23;
	}
	else if(strcmp(desc, "gray10") == 0)
	{
		c[0] = 26;
		c[1] = 26;
		c[2] = 26;
	}
	else if(strcmp(desc, "grey10") == 0)
	{
		c[0] = 26;
		c[1] = 26;
		c[2] = 26;
	}
	else if(strcmp(desc, "gray11") == 0)
	{
		c[0] = 28;
		c[1] = 28;
		c[2] = 28;
	}
	else if(strcmp(desc, "grey11") == 0)
	{
		c[0] = 28;
		c[1] = 28;
		c[2] = 28;
	}
	else if(strcmp(desc, "gray12") == 0)
	{
		c[0] = 31;
		c[1] = 31;
		c[2] = 31;
	}
	else if(strcmp(desc, "grey12") == 0)
	{
		c[0] = 31;
		c[1] = 31;
		c[2] = 31;
	}
	else if(strcmp(desc, "gray13") == 0)
	{
		c[0] = 33;
		c[1] = 33;
		c[2] = 33;
	}
	else if(strcmp(desc, "grey13") == 0)
	{
		c[0] = 33;
		c[1] = 33;
		c[2] = 33;
	}
	else if(strcmp(desc, "gray14") == 0)
	{
		c[0] = 36;
		c[1] = 36;
		c[2] = 36;
	}
	else if(strcmp(desc, "grey14") == 0)
	{
		c[0] = 36;
		c[1] = 36;
		c[2] = 36;
	}
	else if(strcmp(desc, "gray15") == 0)
	{
		c[0] = 38;
		c[1] = 38;
		c[2] = 38;
	}
	else if(strcmp(desc, "grey15") == 0)
	{
		c[0] = 38;
		c[1] = 38;
		c[2] = 38;
	}
	else if(strcmp(desc, "gray16") == 0)
	{
		c[0] = 41;
		c[1] = 41;
		c[2] = 41;
	}
	else if(strcmp(desc, "grey16") == 0)
	{
		c[0] = 41;
		c[1] = 41;
		c[2] = 41;
	}
	else if(strcmp(desc, "gray17") == 0)
	{
		c[0] = 43;
		c[1] = 43;
		c[2] = 43;
	}
	else if(strcmp(desc, "grey17") == 0)
	{
		c[0] = 43;
		c[1] = 43;
		c[2] = 43;
	}
	else if(strcmp(desc, "gray18") == 0)
	{
		c[0] = 46;
		c[1] = 46;
		c[2] = 46;
	}
	else if(strcmp(desc, "grey18") == 0)
	{
		c[0] = 46;
		c[1] = 46;
		c[2] = 46;
	}
	else if(strcmp(desc, "gray19") == 0)
	{
		c[0] = 48;
		c[1] = 48;
		c[2] = 48;
	}
	else if(strcmp(desc, "grey19") == 0)
	{
		c[0] = 48;
		c[1] = 48;
		c[2] = 48;
	}
	else if(strcmp(desc, "gray20") == 0)
	{
		c[0] = 51;
		c[1] = 51;
		c[2] = 51;
	}
	else if(strcmp(desc, "grey20") == 0)
	{
		c[0] = 51;
		c[1] = 51;
		c[2] = 51;
	}
	else if(strcmp(desc, "gray21") == 0)
	{
		c[0] = 54;
		c[1] = 54;
		c[2] = 54;
	}
	else if(strcmp(desc, "grey21") == 0)
	{
		c[0] = 54;
		c[1] = 54;
		c[2] = 54;
	}
	else if(strcmp(desc, "gray22") == 0)
	{
		c[0] = 56;
		c[1] = 56;
		c[2] = 56;
	}
	else if(strcmp(desc, "grey22") == 0)
	{
		c[0] = 56;
		c[1] = 56;
		c[2] = 56;
	}
	else if(strcmp(desc, "gray23") == 0)
	{
		c[0] = 59;
		c[1] = 59;
		c[2] = 59;
	}
	else if(strcmp(desc, "grey23") == 0)
	{
		c[0] = 59;
		c[1] = 59;
		c[2] = 59;
	}
	else if(strcmp(desc, "gray24") == 0)
	{
		c[0] = 61;
		c[1] = 61;
		c[2] = 61;
	}
	else if(strcmp(desc, "grey24") == 0)
	{
		c[0] = 61;
		c[1] = 61;
		c[2] = 61;
	}
	else if(strcmp(desc, "gray25") == 0)
	{
		c[0] = 64;
		c[1] = 64;
		c[2] = 64;
	}
	else if(strcmp(desc, "grey25") == 0)
	{
		c[0] = 64;
		c[1] = 64;
		c[2] = 64;
	}
	else if(strcmp(desc, "gray26") == 0)
	{
		c[0] = 66;
		c[1] = 66;
		c[2] = 66;
	}
	else if(strcmp(desc, "grey26") == 0)
	{
		c[0] = 66;
		c[1] = 66;
		c[2] = 66;
	}
	else if(strcmp(desc, "gray27") == 0)
	{
		c[0] = 69;
		c[1] = 69;
		c[2] = 69;
	}
	else if(strcmp(desc, "grey27") == 0)
	{
		c[0] = 69;
		c[1] = 69;
		c[2] = 69;
	}
	else if(strcmp(desc, "gray28") == 0)
	{
		c[0] = 71;
		c[1] = 71;
		c[2] = 71;
	}
	else if(strcmp(desc, "grey28") == 0)
	{
		c[0] = 71;
		c[1] = 71;
		c[2] = 71;
	}
	else if(strcmp(desc, "gray29") == 0)
	{
		c[0] = 74;
		c[1] = 74;
		c[2] = 74;
	}
	else if(strcmp(desc, "grey29") == 0)
	{
		c[0] = 74;
		c[1] = 74;
		c[2] = 74;
	}
	else if(strcmp(desc, "gray30") == 0)
	{
		c[0] = 77;
		c[1] = 77;
		c[2] = 77;
	}
	else if(strcmp(desc, "grey30") == 0)
	{
		c[0] = 77;
		c[1] = 77;
		c[2] = 77;
	}
	else if(strcmp(desc, "gray31") == 0)
	{
		c[0] = 79;
		c[1] = 79;
		c[2] = 79;
	}
	else if(strcmp(desc, "grey31") == 0)
	{
		c[0] = 79;
		c[1] = 79;
		c[2] = 79;
	}
	else if(strcmp(desc, "gray32") == 0)
	{
		c[0] = 82;
		c[1] = 82;
		c[2] = 82;
	}
	else if(strcmp(desc, "grey32") == 0)
	{
		c[0] = 82;
		c[1] = 82;
		c[2] = 82;
	}
	else if(strcmp(desc, "gray33") == 0)
	{
		c[0] = 84;
		c[1] = 84;
		c[2] = 84;
	}
	else if(strcmp(desc, "grey33") == 0)
	{
		c[0] = 84;
		c[1] = 84;
		c[2] = 84;
	}
	else if(strcmp(desc, "gray34") == 0)
	{
		c[0] = 87;
		c[1] = 87;
		c[2] = 87;
	}
	else if(strcmp(desc, "grey34") == 0)
	{
		c[0] = 87;
		c[1] = 87;
		c[2] = 87;
	}
	else if(strcmp(desc, "gray35") == 0)
	{
		c[0] = 89;
		c[1] = 89;
		c[2] = 89;
	}
	else if(strcmp(desc, "grey35") == 0)
	{
		c[0] = 89;
		c[1] = 89;
		c[2] = 89;
	}
	else if(strcmp(desc, "gray36") == 0)
	{
		c[0] = 92;
		c[1] = 92;
		c[2] = 92;
	}
	else if(strcmp(desc, "grey36") == 0)
	{
		c[0] = 92;
		c[1] = 92;
		c[2] = 92;
	}
	else if(strcmp(desc, "gray37") == 0)
	{
		c[0] = 94;
		c[1] = 94;
		c[2] = 94;
	}
	else if(strcmp(desc, "grey37") == 0)
	{
		c[0] = 94;
		c[1] = 94;
		c[2] = 94;
	}
	else if(strcmp(desc, "gray38") == 0)
	{
		c[0] = 97;
		c[1] = 97;
		c[2] = 97;
	}
	else if(strcmp(desc, "grey38") == 0)
	{
		c[0] = 97;
		c[1] = 97;
		c[2] = 97;
	}
	else if(strcmp(desc, "gray39") == 0)
	{
		c[0] = 99;
		c[1] = 99;
		c[2] = 99;
	}
	else if(strcmp(desc, "grey39") == 0)
	{
		c[0] = 99;
		c[1] = 99;
		c[2] = 99;
	}
	else if(strcmp(desc, "gray40") == 0)
	{
		c[0] = 102;
		c[1] = 102;
		c[2] = 102;
	}
	else if(strcmp(desc, "grey40") == 0)
	{
		c[0] = 102;
		c[1] = 102;
		c[2] = 102;
	}
	else if(strcmp(desc, "gray41") == 0)
	{
		c[0] = 105;
		c[1] = 105;
		c[2] = 105;
	}
	else if(strcmp(desc, "grey41") == 0)
	{
		c[0] = 105;
		c[1] = 105;
		c[2] = 105;
	}
	else if(strcmp(desc, "gray42") == 0)
	{
		c[0] = 107;
		c[1] = 107;
		c[2] = 107;
	}
	else if(strcmp(desc, "grey42") == 0)
	{
		c[0] = 107;
		c[1] = 107;
		c[2] = 107;
	}
	else if(strcmp(desc, "gray43") == 0)
	{
		c[0] = 110;
		c[1] = 110;
		c[2] = 110;
	}
	else if(strcmp(desc, "grey43") == 0)
	{
		c[0] = 110;
		c[1] = 110;
		c[2] = 110;
	}
	else if(strcmp(desc, "gray44") == 0)
	{
		c[0] = 112;
		c[1] = 112;
		c[2] = 112;
	}
	else if(strcmp(desc, "grey44") == 0)
	{
		c[0] = 112;
		c[1] = 112;
		c[2] = 112;
	}
	else if(strcmp(desc, "gray45") == 0)
	{
		c[0] = 115;
		c[1] = 115;
		c[2] = 115;
	}
	else if(strcmp(desc, "grey45") == 0)
	{
		c[0] = 115;
		c[1] = 115;
		c[2] = 115;
	}
	else if(strcmp(desc, "gray46") == 0)
	{
		c[0] = 117;
		c[1] = 117;
		c[2] = 117;
	}
	else if(strcmp(desc, "grey46") == 0)
	{
		c[0] = 117;
		c[1] = 117;
		c[2] = 117;
	}
	else if(strcmp(desc, "gray47") == 0)
	{
		c[0] = 120;
		c[1] = 120;
		c[2] = 120;
	}
	else if(strcmp(desc, "grey47") == 0)
	{
		c[0] = 120;
		c[1] = 120;
		c[2] = 120;
	}
	else if(strcmp(desc, "gray48") == 0)
	{
		c[0] = 122;
		c[1] = 122;
		c[2] = 122;
	}
	else if(strcmp(desc, "grey48") == 0)
	{
		c[0] = 122;
		c[1] = 122;
		c[2] = 122;
	}
	else if(strcmp(desc, "gray49") == 0)
	{
		c[0] = 125;
		c[1] = 125;
		c[2] = 125;
	}
	else if(strcmp(desc, "grey49") == 0)
	{
		c[0] = 125;
		c[1] = 125;
		c[2] = 125;
	}
	else if(strcmp(desc, "gray50") == 0)
	{
		c[0] = 127;
		c[1] = 127;
		c[2] = 127;
	}
	else if(strcmp(desc, "grey50") == 0)
	{
		c[0] = 127;
		c[1] = 127;
		c[2] = 127;
	}
	else if(strcmp(desc, "gray51") == 0)
	{
		c[0] = 130;
		c[1] = 130;
		c[2] = 130;
	}
	else if(strcmp(desc, "grey51") == 0)
	{
		c[0] = 130;
		c[1] = 130;
		c[2] = 130;
	}
	else if(strcmp(desc, "gray52") == 0)
	{
		c[0] = 133;
		c[1] = 133;
		c[2] = 133;
	}
	else if(strcmp(desc, "grey52") == 0)
	{
		c[0] = 133;
		c[1] = 133;
		c[2] = 133;
	}
	else if(strcmp(desc, "gray53") == 0)
	{
		c[0] = 135;
		c[1] = 135;
		c[2] = 135;
	}
	else if(strcmp(desc, "grey53") == 0)
	{
		c[0] = 135;
		c[1] = 135;
		c[2] = 135;
	}
	else if(strcmp(desc, "gray54") == 0)
	{
		c[0] = 138;
		c[1] = 138;
		c[2] = 138;
	}
	else if(strcmp(desc, "grey54") == 0)
	{
		c[0] = 138;
		c[1] = 138;
		c[2] = 138;
	}
	else if(strcmp(desc, "gray55") == 0)
	{
		c[0] = 140;
		c[1] = 140;
		c[2] = 140;
	}
	else if(strcmp(desc, "grey55") == 0)
	{
		c[0] = 140;
		c[1] = 140;
		c[2] = 140;
	}
	else if(strcmp(desc, "gray56") == 0)
	{
		c[0] = 143;
		c[1] = 143;
		c[2] = 143;
	}
	else if(strcmp(desc, "grey56") == 0)
	{
		c[0] = 143;
		c[1] = 143;
		c[2] = 143;
	}
	else if(strcmp(desc, "gray57") == 0)
	{
		c[0] = 145;
		c[1] = 145;
		c[2] = 145;
	}
	else if(strcmp(desc, "grey57") == 0)
	{
		c[0] = 145;
		c[1] = 145;
		c[2] = 145;
	}
	else if(strcmp(desc, "gray58") == 0)
	{
		c[0] = 148;
		c[1] = 148;
		c[2] = 148;
	}
	else if(strcmp(desc, "grey58") == 0)
	{
		c[0] = 148;
		c[1] = 148;
		c[2] = 148;
	}
	else if(strcmp(desc, "gray59") == 0)
	{
		c[0] = 150;
		c[1] = 150;
		c[2] = 150;
	}
	else if(strcmp(desc, "grey59") == 0)
	{
		c[0] = 150;
		c[1] = 150;
		c[2] = 150;
	}
	else if(strcmp(desc, "gray60") == 0)
	{
		c[0] = 153;
		c[1] = 153;
		c[2] = 153;
	}
	else if(strcmp(desc, "grey60") == 0)
	{
		c[0] = 153;
		c[1] = 153;
		c[2] = 153;
	}
	else if(strcmp(desc, "gray61") == 0)
	{
		c[0] = 156;
		c[1] = 156;
		c[2] = 156;
	}
	else if(strcmp(desc, "grey61") == 0)
	{
		c[0] = 156;
		c[1] = 156;
		c[2] = 156;
	}
	else if(strcmp(desc, "gray62") == 0)
	{
		c[0] = 158;
		c[1] = 158;
		c[2] = 158;
	}
	else if(strcmp(desc, "grey62") == 0)
	{
		c[0] = 158;
		c[1] = 158;
		c[2] = 158;
	}
	else if(strcmp(desc, "gray63") == 0)
	{
		c[0] = 161;
		c[1] = 161;
		c[2] = 161;
	}
	else if(strcmp(desc, "grey63") == 0)
	{
		c[0] = 161;
		c[1] = 161;
		c[2] = 161;
	}
	else if(strcmp(desc, "gray64") == 0)
	{
		c[0] = 163;
		c[1] = 163;
		c[2] = 163;
	}
	else if(strcmp(desc, "grey64") == 0)
	{
		c[0] = 163;
		c[1] = 163;
		c[2] = 163;
	}
	else if(strcmp(desc, "gray65") == 0)
	{
		c[0] = 166;
		c[1] = 166;
		c[2] = 166;
	}
	else if(strcmp(desc, "grey65") == 0)
	{
		c[0] = 166;
		c[1] = 166;
		c[2] = 166;
	}
	else if(strcmp(desc, "gray66") == 0)
	{
		c[0] = 168;
		c[1] = 168;
		c[2] = 168;
	}
	else if(strcmp(desc, "grey66") == 0)
	{
		c[0] = 168;
		c[1] = 168;
		c[2] = 168;
	}
	else if(strcmp(desc, "gray67") == 0)
	{
		c[0] = 171;
		c[1] = 171;
		c[2] = 171;
	}
	else if(strcmp(desc, "grey67") == 0)
	{
		c[0] = 171;
		c[1] = 171;
		c[2] = 171;
	}
	else if(strcmp(desc, "gray68") == 0)
	{
		c[0] = 173;
		c[1] = 173;
		c[2] = 173;
	}
	else if(strcmp(desc, "grey68") == 0)
	{
		c[0] = 173;
		c[1] = 173;
		c[2] = 173;
	}
	else if(strcmp(desc, "gray69") == 0)
	{
		c[0] = 176;
		c[1] = 176;
		c[2] = 176;
	}
	else if(strcmp(desc, "grey69") == 0)
	{
		c[0] = 176;
		c[1] = 176;
		c[2] = 176;
	}
	else if(strcmp(desc, "gray70") == 0)
	{
		c[0] = 179;
		c[1] = 179;
		c[2] = 179;
	}
	else if(strcmp(desc, "grey70") == 0)
	{
		c[0] = 179;
		c[1] = 179;
		c[2] = 179;
	}
	else if(strcmp(desc, "gray71") == 0)
	{
		c[0] = 181;
		c[1] = 181;
		c[2] = 181;
	}
	else if(strcmp(desc, "grey71") == 0)
	{
		c[0] = 181;
		c[1] = 181;
		c[2] = 181;
	}
	else if(strcmp(desc, "gray72") == 0)
	{
		c[0] = 184;
		c[1] = 184;
		c[2] = 184;
	}
	else if(strcmp(desc, "grey72") == 0)
	{
		c[0] = 184;
		c[1] = 184;
		c[2] = 184;
	}
	else if(strcmp(desc, "gray73") == 0)
	{
		c[0] = 186;
		c[1] = 186;
		c[2] = 186;
	}
	else if(strcmp(desc, "grey73") == 0)
	{
		c[0] = 186;
		c[1] = 186;
		c[2] = 186;
	}
	else if(strcmp(desc, "gray74") == 0)
	{
		c[0] = 189;
		c[1] = 189;
		c[2] = 189;
	}
	else if(strcmp(desc, "grey74") == 0)
	{
		c[0] = 189;
		c[1] = 189;
		c[2] = 189;
	}
	else if(strcmp(desc, "gray75") == 0)
	{
		c[0] = 191;
		c[1] = 191;
		c[2] = 191;
	}
	else if(strcmp(desc, "grey75") == 0)
	{
		c[0] = 191;
		c[1] = 191;
		c[2] = 191;
	}
	else if(strcmp(desc, "gray76") == 0)
	{
		c[0] = 194;
		c[1] = 194;
		c[2] = 194;
	}
	else if(strcmp(desc, "grey76") == 0)
	{
		c[0] = 194;
		c[1] = 194;
		c[2] = 194;
	}
	else if(strcmp(desc, "gray77") == 0)
	{
		c[0] = 196;
		c[1] = 196;
		c[2] = 196;
	}
	else if(strcmp(desc, "grey77") == 0)
	{
		c[0] = 196;
		c[1] = 196;
		c[2] = 196;
	}
	else if(strcmp(desc, "gray78") == 0)
	{
		c[0] = 199;
		c[1] = 199;
		c[2] = 199;
	}
	else if(strcmp(desc, "grey78") == 0)
	{
		c[0] = 199;
		c[1] = 199;
		c[2] = 199;
	}
	else if(strcmp(desc, "gray79") == 0)
	{
		c[0] = 201;
		c[1] = 201;
		c[2] = 201;
	}
	else if(strcmp(desc, "grey79") == 0)
	{
		c[0] = 201;
		c[1] = 201;
		c[2] = 201;
	}
	else if(strcmp(desc, "gray80") == 0)
	{
		c[0] = 204;
		c[1] = 204;
		c[2] = 204;
	}
	else if(strcmp(desc, "grey80") == 0)
	{
		c[0] = 204;
		c[1] = 204;
		c[2] = 204;
	}
	else if(strcmp(desc, "gray81") == 0)
	{
		c[0] = 207;
		c[1] = 207;
		c[2] = 207;
	}
	else if(strcmp(desc, "grey81") == 0)
	{
		c[0] = 207;
		c[1] = 207;
		c[2] = 207;
	}
	else if(strcmp(desc, "gray82") == 0)
	{
		c[0] = 209;
		c[1] = 209;
		c[2] = 209;
	}
	else if(strcmp(desc, "grey82") == 0)
	{
		c[0] = 209;
		c[1] = 209;
		c[2] = 209;
	}
	else if(strcmp(desc, "gray83") == 0)
	{
		c[0] = 212;
		c[1] = 212;
		c[2] = 212;
	}
	else if(strcmp(desc, "grey83") == 0)
	{
		c[0] = 212;
		c[1] = 212;
		c[2] = 212;
	}
	else if(strcmp(desc, "gray84") == 0)
	{
		c[0] = 214;
		c[1] = 214;
		c[2] = 214;
	}
	else if(strcmp(desc, "grey84") == 0)
	{
		c[0] = 214;
		c[1] = 214;
		c[2] = 214;
	}
	else if(strcmp(desc, "gray85") == 0)
	{
		c[0] = 217;
		c[1] = 217;
		c[2] = 217;
	}
	else if(strcmp(desc, "grey85") == 0)
	{
		c[0] = 217;
		c[1] = 217;
		c[2] = 217;
	}
	else if(strcmp(desc, "gray86") == 0)
	{
		c[0] = 219;
		c[1] = 219;
		c[2] = 219;
	}
	else if(strcmp(desc, "grey86") == 0)
	{
		c[0] = 219;
		c[1] = 219;
		c[2] = 219;
	}
	else if(strcmp(desc, "gray87") == 0)
	{
		c[0] = 222;
		c[1] = 222;
		c[2] = 222;
	}
	else if(strcmp(desc, "grey87") == 0)
	{
		c[0] = 222;
		c[1] = 222;
		c[2] = 222;
	}
	else if(strcmp(desc, "gray88") == 0)
	{
		c[0] = 224;
		c[1] = 224;
		c[2] = 224;
	}
	else if(strcmp(desc, "grey88") == 0)
	{
		c[0] = 224;
		c[1] = 224;
		c[2] = 224;
	}
	else if(strcmp(desc, "gray89") == 0)
	{
		c[0] = 227;
		c[1] = 227;
		c[2] = 227;
	}
	else if(strcmp(desc, "grey89") == 0)
	{
		c[0] = 227;
		c[1] = 227;
		c[2] = 227;
	}
	else if(strcmp(desc, "gray90") == 0)
	{
		c[0] = 229;
		c[1] = 229;
		c[2] = 229;
	}
	else if(strcmp(desc, "grey90") == 0)
	{
		c[0] = 229;
		c[1] = 229;
		c[2] = 229;
	}
	else if(strcmp(desc, "gray91") == 0)
	{
		c[0] = 232;
		c[1] = 232;
		c[2] = 232;
	}
	else if(strcmp(desc, "grey91") == 0)
	{
		c[0] = 232;
		c[1] = 232;
		c[2] = 232;
	}
	else if(strcmp(desc, "gray92") == 0)
	{
		c[0] = 235;
		c[1] = 235;
		c[2] = 235;
	}
	else if(strcmp(desc, "grey92") == 0)
	{
		c[0] = 235;
		c[1] = 235;
		c[2] = 235;
	}
	else if(strcmp(desc, "gray93") == 0)
	{
		c[0] = 237;
		c[1] = 237;
		c[2] = 237;
	}
	else if(strcmp(desc, "grey93") == 0)
	{
		c[0] = 237;
		c[1] = 237;
		c[2] = 237;
	}
	else if(strcmp(desc, "gray94") == 0)
	{
		c[0] = 240;
		c[1] = 240;
		c[2] = 240;
	}
	else if(strcmp(desc, "grey94") == 0)
	{
		c[0] = 240;
		c[1] = 240;
		c[2] = 240;
	}
	else if(strcmp(desc, "gray95") == 0)
	{
		c[0] = 242;
		c[1] = 242;
		c[2] = 242;
	}
	else if(strcmp(desc, "grey95") == 0)
	{
		c[0] = 242;
		c[1] = 242;
		c[2] = 242;
	}
	else if(strcmp(desc, "gray96") == 0)
	{
		c[0] = 245;
		c[1] = 245;
		c[2] = 245;
	}
	else if(strcmp(desc, "grey96") == 0)
	{
		c[0] = 245;
		c[1] = 245;
		c[2] = 245;
	}
	else if(strcmp(desc, "gray97") == 0)
	{
		c[0] = 247;
		c[1] = 247;
		c[2] = 247;
	}
	else if(strcmp(desc, "grey97") == 0)
	{
		c[0] = 247;
		c[1] = 247;
		c[2] = 247;
	}
	else if(strcmp(desc, "gray98") == 0)
	{
		c[0] = 250;
		c[1] = 250;
		c[2] = 250;
	}
	else if(strcmp(desc, "grey98") == 0)
	{
		c[0] = 250;
		c[1] = 250;
		c[2] = 250;
	}
	else if(strcmp(desc, "gray99") == 0)
	{
		c[0] = 252;
		c[1] = 252;
		c[2] = 252;
	}
	else if(strcmp(desc, "grey99") == 0)
	{
		c[0] = 252;
		c[1] = 252;
		c[2] = 252;
	}
	else if(strcmp(desc, "gray100") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "grey100") == 0)
	{
		c[0] = 255;
		c[1] = 255;
		c[2] = 255;
	}
	else if(strcmp(desc, "DarkGrey") == 0)
	{
		c[0] = 169;
		c[1] = 169;
		c[2] = 169;
	}
	else if(strcmp(desc, "DarkGray") == 0)
	{
		c[0] = 169;
		c[1] = 169;
		c[2] = 169;
	}
	else if(strcmp(desc, "DarkBlue") == 0)
	{
		c[0] = 0;
		c[1] = 0;
		c[2] = 139;
	}
	else if(strcmp(desc, "DarkCyan") == 0)
	{
		c[0] = 0;
		c[1] = 139;
		c[2] = 139;
	}
	else if(strcmp(desc, "DarkMagenta") == 0)
	{
		c[0] = 139;
		c[1] = 0;
		c[2] = 139;
	}
	else if(strcmp(desc, "DarkRed") == 0)
	{
		c[0] = 139;
		c[1] = 0;
		c[2] = 0;
	}
	else if(strcmp(desc, "LightGreen") == 0)
	{
		c[0] = 144;
		c[1] = 238;
		c[2] = 144;
	}
	else
	{
		fprintf(stderr, "Invalid color %s.\n", desc);
		exit(1);
	}
	return c;
}
