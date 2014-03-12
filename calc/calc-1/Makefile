calc : calc.l calc.y
	bison -d calc.y
	flex calc.l
	cc -o $@ calc.tab.c lex.yy.c -lfl


.PHONY : clean
clean :
	-rm lex.yy.c calc.tab.* calc
