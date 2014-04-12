%{
#include <stdio.h>
#include <stdlib.h>
#include "lisp.h"
%}

%union {
	struct ast *a;
}

%token SYMBOL NUMBER OP

%type <a> list expr

%start list
%%
block : list ';' { printf("A block\n"); }
	  ;

list : '(' expr ')' { $$ = newast('L', $2, NULL); } 
	 ;

expr :  { $$ = NULL; }
	 | expr SYMBOL { $$ = newast('S', $1, $2); }
	 | expr NUMBER { $$ = newast('N', $1, $2); }
	 | expr '+'    { $$ = newast('+', $1, $2); }
	 | expr '-'    { $$ = newast('-', $1, $2); }
	 | expr	'*'    { $$ = newast('*', $1, $2); }
	 | expr '/'    { $$ = newast('/', $1, $2); }
	 | expr list   { $$ = newast('L', $1, $2); }
	 ;

%%

int main(int argc, char *argv[])
{
	yyparse();
	
	return 0;
}
