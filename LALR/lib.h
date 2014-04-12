#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED

#include <vector>
#include <string>
#include <map>
using namespace std;



//产生式右侧 元
struct sym_t {
    sym_t() {}
    sym_t(bool a, const string &b): is_term(a), sym(b) {}
    bool is_term;
    string sym;
};

//production type 扩展产生式类型 右端
struct prod_t {
    vector<sym_t> sym_list;  //产生式右侧 符号 列表
    int dot;    //扩展产生式的 . 符号位置
};

//每个状态中的产生式
struct state_t {
    vector<prod_t> prod;
};

extern vector<state_t> s;
extern vector<string> term_list; //终结符列表
extern vector<string> nterm_list;//非终结符列表


extern map<string, vector<prod_t> > nterm_prod; //非终结符对应的产生式

void Generate_state();
void Init();

#endif // LEX_H_INCLUDED
