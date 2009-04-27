%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common/list.h"
#include "../common/replace.h"

typedef struct {
	char* define;
	char* value;
} Definition;

extern int line_no;
char* source;
List* l;

void yyerror(const char *s)
{
	fprintf(stderr, "xswpp: preprocessor error: %s in line %d\n", s, 
		line_no);
	exit(1);
}

int main()
{
	l = list();
	yyparse();
	return 0;
}

%}

%token INCLUDE DEFINE
%token <c> DEF_ID LINE

%union {
	char* c;
}

%%

lines:
     | lines line

line: preprocessor
    | source

source: LINE
{
	List* ll = l;
	while(ll)
	{
		Definition* def = (Definition)ll->data;
		ll = ll->next;
	}
}

preprocessor: DEFINE DEF_ID
{
	char* define = strsep(&$2, " ");

	Definition* d = malloc(sizeof(Definition));
	d->define = define;
	d->value = $2;

	ladd(l, (void*)d);
}

%%
