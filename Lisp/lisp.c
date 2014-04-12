#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lisp.h"

void yyerror(char *s, ...)
{
	va_list ap;
	va_start(ap, s);

	fprintf(stderr, "%d: error: ", yylineno);
	vfprintf(stderr, s, ap);

	fprintf(stderr, "\n");
}

struct ast *newast(int nodetype, struct ast *l, struct ast *r)
{
	struct ast *a = malloc(sizeof(struct ast));

	if (!a) {
		yyerror("out of space");
		exit(0);
	}

	a->nodetype = nodetype;
	a->l = l;
	a->r = r;
	return a;
}
