#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "token.h"

int lineno = 1;
int buffer_len = 0;
char buffer[BUFSIZE];
/*
FILE *FILEIN  = stdin;
FILE *FILEOUT = stdout;
*/

void reset_buffer()
{
    buffer[buffer_len=0] = 0;
}

void push_buffer(char c)
{
    buffer[buffer_len++] = c;
    buffer[buffer_len] = 0;
}

void lex_error(char c)
{
    fprintf(stderr, "error at line : %d => %c\n", lineno, c);
}

token_t next_token()
{
    int next_char, c;

    reset_buffer();

    while ((next_char = getchar()) != EOF) {
        if (next_char == '\n') {
            lineno++;
            continue;
        }
        if (isspace(next_char))
            continue ;

        push_buffer(next_char);

        if (isalpha(next_char)) {
            /*
                标识符
                [a-zA-Z]+[a-zA-Z0-9_]*
            */
            for (c=getchar(); isalpha(c) || isdigit(c) || c=='_'; c=getchar())
                push_buffer(c);
            ungetc(c, stdin);

            if (!strcmp("int", buffer)) return INT;
            if (!strcmp("if", buffer))  return IF;
            if (!strcmp("else", buffer))return ELSE;
            if (!strcmp("while", buffer)) return WHILE;
            if (!strcmp("do", buffer))  return DO;
            if (!strcmp("return", buffer)) return RETURN;

            return SYMBOL;
        }
        if (isdigit(next_char)) {
            /*
                数值型：只识别整数
                整数： [0-9]+
                浮点数：[0-9]+.[0-9]+
            */
            for (c=getchar(); isdigit(c); c=getchar())
                push_buffer(c);
            ungetc(c, stdin);
            return NUMBER;
        }

        if (next_char == '"') {
            /*
            字符串识别
            */
            while ((c = getchar()) != '"') {
                if (c == '\\') {
                    c = getchar();
                    switch (c) {
                        case 'a': push_buffer('\a'); break;
                        case 'b': push_buffer('\b'); break;
                        case 'f': push_buffer('\f'); break;
                        case 'n': push_buffer('\n'); break;
                        case 'r': push_buffer('\r'); break;
                        case 't': push_buffer('\t'); break;
                        case 'v': push_buffer('\v'); break;
                        case '\\':push_buffer('\\'); break;
                        case '?': push_buffer('\?'); break;
                        case '\'':push_buffer('\''); break;
                        case '"': push_buffer('\"'); break;
                        default: ungetc(c, stdin); break;
                    }
                } else push_buffer(c);
            }
            return STRING;
        }
        switch (next_char) {
            case '+': return PLUSOP;
            case '-': return MINUSOP;
            case '*': return MULTIOP;
            case '/': return DIVOP;
            case '(': return LP;
            case ')': return RP;
            case '[': return LS;
            case ']': return RS;
            case '{': return LB;
            case '}': return RB;
            case ',': return COMMA;
            case ';': return SEMICOLON;
            case '=':
                next_char = getchar();
                if (next_char == '=') {
                    push_buffer(next_char);
                    return EQ;
                }
                ungetc(next_char, stdin);
                return ASSIGN;
            case '<':
                next_char = getchar();
                if (next_char == '=') {
                    push_buffer(next_char);
                    return LE;
                }
                ungetc(next_char, stdin);
                return LT;
            case '>':
                next_char = getchar();
                if (next_char == '=') {
                    push_buffer(next_char);
                    return GE;
                }
                ungetc(next_char, stdin);
                return GT;
            case '!':
                next_char = getchar();
                if (next_char == '=') {
                    push_buffer(next_char);
                    return NE;
                }
                lex_error(next_char);
                break;
            default:
                lex_error(next_char);
                break;
        }
        lex_error(next_char);
    }
    return END;
}







