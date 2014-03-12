wc : wc.lex
	flex wc.lex
	cc -o $@ lex.yy.c -lfl

word : word.lex
	flex word.lex
	cc -o $@ lex.yy.c -lfl
clean :
	rm lex.yy.c wc word 
