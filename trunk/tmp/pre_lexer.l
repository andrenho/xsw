%{

#include "pre_parser.h"

int pre_line_no = 1;

%}

%option nounput
%option noinput

%option prefix="pre_"

%%

.						return OTHER;
\n						pre_line_no++; return OTHER;
^\%include[ |\t]?[\"|\'].*[\"|\'][ |\t]?	return INCLUDE;

%%
