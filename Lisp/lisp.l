%option noyywrap nodefault yylineno
%{
#include "lisp.tab.h"

%}
%%
"+" |
"-" |
"*" |
"/" |
"(" |
")" |
";" { return yytext[0]; }

[a-zA-Z][-a-zA-Z0-9]* { return SYMBOL; }

-?[0-9]+ { return NUMBER; }

[ \t\n] { }

. { printf("Mystery character %c\n", *yytext); }
%%
