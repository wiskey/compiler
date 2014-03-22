#ifndef _TOKEN_H_
#define _TOKEN_H_


typedef enum token token_t;

enum token {
    /* 关键字 */
    INT = 1,
    IF, ELSE, WHILE, DO, RETURN,

    /* 标识符 */
    SYMBOL,

    /* 数值 */
    NUMBER,   // 整数

    /* 各种符号 */
    PLUSOP,     // '+'
    MINUSOP,    // '-'
    MULTIOP,    // '*'
    DIVOP,      // '/'
    MODOP,      // '%'

    COMMA,      // ','
    SEMICOLON,  // ';'
    ASSIGN,     // '='
    EQ,         // '=='
    LT,         // '<'
    GT,         // '>'
    LE,         // '<='
    GE,         // '>='
    NE,         // '!='
    LS,         // '['
    RS,         // ']'
    LP,         // '('   left  parenthese
    RP,         // ')'   right parenthese
    LB,         // '{'   left brace
    RB,         // '}'   right brace

    STRING,     // 表示一个字符串

    // DQUOTE,     // '"' 双引号  double quote
    // SQUOTE,     // '   单引号  sigle quote




    END         // 文件结束，或输入结束
};

extern int lineno;

#define BUFSIZE 1024
extern char buffer[];
extern int buffer_len;

token_t next_token();
void lex_error(char );
void reset_buffer();
void push_buffer(char );
#endif













