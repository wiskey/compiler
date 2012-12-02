#include <stdio.h>
#include <ctype.h>
#include "token.h"


extern char token_buffer[];
void buffer_char(char c) {

}
token check_reserved() {}

void lexical_error(char error_char) {
    printf("Error charactor : %c\n", error_char);
}
extern token scanner() {
    int in_char, c;

    while ((in_char = getchar()) != EOF) {
        if (isspace(in_char))
            continue;
        else if (isalpha(in_char)) {
            /*
             * ID ::= LERRER | ID LETTER
             *               | ID DIGIT
             *               | ID UNDERSCORE
             */
            buffer_char(in_char);
            for (c=getchar(); isalpha(c) || isdigit(c) || c=='_'; c=getchar())
                buffer_char(c);
            ungetc(c, stdin);
            return check_reserved();
        } else if (isdigit(in_char)) {
            /*
             * INTLITERAL ::= DIGIT | INTLITERAL
             */
            while (isdigit((c = getchar())))
                buffer_char(c);
            ungetc(c, stdin);
            return INTLITERAL;
        } else if (in_char == '(')
            return LPAREN;
        else if (in_char == ')')
            return RPAREN;
        else if (in_char == ';')
            return SEMICOLON;
        else if (in_char == ',')
            return COMMA;
        else if (in_char == '+')
            return PLUSOP;
        else if (in_char == ':') {
            /*looking for := */
            c = getchar();
            if (c == '=')
                return ASSIGNOP;
            else {
                ungetc(c, stdin);
                lexical_error(in_char);
            }
        } else if (in_char == '-') {
            /* is it --, comment start */
            c = getchar();
            if (c == '-') {
                for (c=getchar(); c!='\n'; c=getchar()) ;
            } else {
                ungetc(c, stdin);
                return MINUSOP;
            }
        } else
            lexical_error(in_char);
    }
}

int main() {

    return 0;
}







