#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED

#include <vector>
#include <string>
#include <map>
using namespace std;



//产生式右侧 元
struct sym_t {
    sym_t() {}
    sym_t(bool a, int b): is_term(a), sym(b) {}
    bool is_term;
    int sym;
};

//production type 产生式类型
struct prod_t {
    int nterm;      // 左侧非终结符
    vector<sym_t> sym_list;  //产生式右侧 符号 列表
};

struct prodd {
    int prod_id;  //产生式的下标
    int dot;        // . 所在的位置
    vector<int> pre; //提前扫描的终结符
};

//每个状态中的产生式
struct state_t {
    vector<prodd> prod;
    map<int, int> term_next; //终结符对应的状态
    map<int, int> nterm_next; //非终结符对应的状态
};

extern vector<state_t> State;

//记录所有的产生式
extern vector<prod_t> prod;
extern map<string, int> term_id;    //终结符编号
extern map<string, int> nterm_id;   //非终结符编号

void Generate_state();
void Init();

#endif // LEX_H_INCLUDED
