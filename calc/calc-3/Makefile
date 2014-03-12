calc : calc.l calc.y calc.c calc.h
	bison -d calc.y
	flex calc.l 
	cc -o calc lex.yy.c calc.c calc.tab.c calc.h calc.tab.h -lfl -lm

.PHONY : clean

clean :
	-rm lex.yy.c calc.tab.c calc calc.tab.h
