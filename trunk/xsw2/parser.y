%{

#include <stdio.h>

extern int line_no;

void yyerror(const char *s)
{
	fprintf(stderr, "parser error: %s in line %d\n", s, line_no);
	exit(1);
}

int yywrap()
{
	return 1;
}

/*
int main()
{
	yyparse();
	return 0;
}
*/

%}

// single tokens
%token ENTER EQUALS SET COLON AT PLUS MINUS MULTIPLY DIVIDE LPAREN RPAREN 
%token MORE_THAN LESS_THAN LESS_EQUAL MORE_EQUAL

// constants
%token WHILE END DEF

// expressions
%token ID VARIABLE NUMBER STRING
// %token <d> NUMBER 
// %token <c> STRING

%%

file: directives

directives: 
	  | directives directive

directive: regular
	 | function 

regulars:
	| regulars regular

regular: attribution
       | f_call
       | command

function: DEF ID COLON ENTER regulars END ENTER

attribution: VARIABLE SET expression ENTER { printf("attribution\n"); }

f_call: ID COLON expression parameters ENTER { printf("function (1)\n"); }
      | ID COLON parameters ENTER { printf("function (2)\n"); }
      | STRING parameters ENTER { printf("function (3)\n"); }
      | AT { printf("function (4)\n"); }

command: WHILE expression ENTER regulars END ENTER

parameters: 
	  | parameters parameter

parameter: ID COLON expression
	 | ID

expression: STRING
          | expr
//          | constant

/*
 * Expressions
 */
expr: expr PLUS term        // { $$ =  + ; }
    | expr MINUS term       // { $$ =  - ; }
    | term

term: term MULTIPLY compare  // { $$ =  * ; }
    | term DIVIDE compare    // { $$ =  / ; }
    | compare

compare: term LESS_THAN factor
       | term MORE_THAN factor
       | term LESS_EQUAL factor
       | term MORE_EQUAL factor
       | term EQUALS factor
       | factor

factor: LPAREN expr RPAREN  // { $$ = ; }
      | value

value: NUMBER
     | VARIABLE


%%
