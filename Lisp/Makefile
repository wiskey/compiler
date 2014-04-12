all : lisp

lisp : lisp.l lisp.y
	bison -d lisp.y
	flex lisp.l
	gcc -o lisp lisp.c lex.yy.c lisp.tab.c lisp.h lisp.tab.h -lfl

.PHONY : clean

clean :
	-rm lex.yy.c lisp lisp.tab.*
