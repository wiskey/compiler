#include "statement.h"

token next_token() {

}
void match(token tok) {

}
void syntax_error(token tok) {

}
void add_op() {
    /* <addop> ::= PLUSOP | MINUSOP */

    token tok = next_token();
    if (tok == PLUSOP || tok == MINUSOP)
        match(tok);
    else
        syntax_error(tok);
}
void expression() {
    /* <expression> ::= <primary>
     *                   | { <add op> <primary> }
     */
    token t;
    primary();
    for (t = next_token(); t == PLUSOP || t == MINUSOP;
                        t = next_token()) {
        add_op();
        primary();
    }
}
void primary() {
    token tok = next_token();

    switch (tok) {
        case LPAREN:
            /* <primary> ::= ( <expression> ) */
            match(LPAREN);
            expression();
            match(RPAREN);
            break;
        case ID:
            /* <primary> ::= ID */
            match(ID);
            break;
        case INTLITERAL:
            /* <primaty> ::= INTLITERAL */
            match(INTLITERAL);
            break;
        default:
            syntax_error(tok);
            break;
    }
}

void id_list() {
    /* <id list> ::= ID { , ID } */
    match(ID);
    while (next_token() == COMMA) {
        match(COMMA);
        match(ID);
    }
}
void expr_list() {
    /* <expr list> ::= <expression> { , <expression> } */
    expression();

    while (next_token() == COMMA) {
        match(COMMA);
        expression();
    }
}

void statement() {
    token tok = next_token();

    switch (tok) {
        case ID:
            /* <statement> ::= ID := <expression>; */
            match(ID); match(ASSIGNOP);
            expression(); match(SEMICOLON);
            break;
        case READ:
            /* <statement> ::= READ ( <id list> ); */
            match(READ); match(LPAREN);
            id_list(); match(RPAREN);
            match(SEMICOLON);
            break;
        case WRITE:
            /* <statement> ::= WRITE ( <expr list> ); */
            match(WRITE); match(LPAREN);
            expr_list(); match(RPAREN);
            match(SEMICOLON);
            break;
        default:
            syntax_error(tok);
            break;
    }
}
void statement_list() {
    /*
     * statement_list ::= <statement> {<statement>}
     */
    statement();
    while ( TRUE ) {
        switch (next_token()) {
            case ID:
            case READ:
            case WRITE:
                statement();
                break;
            default:
                return ;
        }
    }
}
void program() {
    /* <program> ::= BEGIN <statement list> END */
    match(BEGIN);
    statement_list();
    match(END);
}
void system_goal() {
    /* <system goal> ::= <program> SCANEOF */
    program();
    match(SCANEOF);
}

int main() {
    return 0;
}














