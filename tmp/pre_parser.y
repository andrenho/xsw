%{

#include <stdio.h>

extern int pre_line_no;

void pre_error(const char *s)
{
	fprintf(stderr, "parser error: %s in line %d\n", s, pre_line_no);
	exit(1);
}

int pre_wrap()
{
	return 1;
}

%}

%name-prefix="pre_"

%token INCLUDE OTHER

%%

strings: 
       | strings string

string: INCLUDE { printf("INCLUDE\n"); }
      | OTHER { printf("other\n"); }

%%
