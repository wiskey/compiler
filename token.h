
typedef enum token_types {
    BEGIN, END, READ, WRITE, ID, INTLITERAL,
    LPAREN, RPAREN, SEMICOLON, COMMA, ASSIGNOP,
    PLUSOP, MINUSOP, SCANEOF
} token;

void buffer_char(char) ;
token check_reserved() ;
void lexical_error(char) ;
extern token scanner() ;
