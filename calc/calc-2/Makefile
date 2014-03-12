calc : calc.l calc.y calc.h
	bison -d calc.y
	flex -o calc.lex.c calc.l
	cc -o $@ calc.tab.c calc.lex.c calc.c

.PHONY : clean
clean :
	rm calc calc.lex.c calc.tab.*
