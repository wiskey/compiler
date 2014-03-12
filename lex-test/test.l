%{
%}


EXP = ([Ee][-+]?[0-9]+)

%%

"+" |
"-" { return NUMBER; }

"<"	{ yylval.fn = int(1); return }
[0-9]+"."[0-9]*{EXP}? { return NUMBER; }


%%
