
extern int yylineno;
void yyerror(char *s, ...);

struct ast {
	int nodetype;
	struct ast *l;
	struct ast *r;
};

struct ast *newast(int nodetype, struct ast *l, struct ast *r);
