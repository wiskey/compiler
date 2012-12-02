#include "token.h"
#define TRUE 1

token next_token();
void match(token tok) ;
void syntax_error(token) ;
void add_op() ;
void expression() ;
void primary() ;
void id_list() ;
void expr_list() ;
void statement() ;
void statement_list();
void program() ;
void system_goal() ;
