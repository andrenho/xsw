%{

#include "parser.h"

int line_no = 1;

%}

number		[\-]?[0-9]*[\.]?[0-9]*
string		\".*\"|\'.*\'
id		[a-zA-Z][a-zA-Z0-9\_]*
variable	\$[a-zA-Z][a-zA-Z0-9\_]*

%option nounput
%option noinput

%%

^[ \t]*#.*\n		line_no++; // ignore comments
#.*\n			line_no++; return ENTER; // ignore midline comment
[ \t]			; // ignore spaces
^[ \t]*\n		line_no++; // ignore empty lines

\n			line_no++; return ENTER;
=			return SET;
:			return COLON;
@			return AT;
\+			return PLUS;
\-			return MINUS;
\<			return LESS_THAN;
\>			return MORE_THAN;
\<=			return LESS_EQUAL;
\>=			return MORE_EQUAL;
==			return EQUALS;
\*			return MULTIPLY;
\/			return DIVIDE;
\(			return LPAREN;
\)			return RPAREN;

while			return WHILE;
end			return END;
def			return DEF;

{number}		return NUMBER;
{string}		return STRING;
{variable}		return VARIABLE;
{id}			return ID;

%%
