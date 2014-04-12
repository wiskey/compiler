#include <iostream>
#include <string>
#include <cstdio>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "lib.h"
using namespace std;

vector<prod_t> prod;              //所有产生式
vector< vector<int> > nterm_prod; //非终结符对应的产生式
map<string, int> term_id;    //终结符编号
map<string, int> nterm_id;   //非终结符编号
vector<state_t> State;      //所有的状态集合

//打印识别的产生式信息表
static void print_info() {
    freopen("Table", "w", stdout);

    map<string, int>::iterator it;

    printf("term_cnt: %d\n", term_id.size());
    for (it=term_id.begin(); it!=term_id.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }


    cout << endl << endl;

    printf("nterm_cnt: %d\n", nterm_id.size());
    for (it=nterm_id.begin(); it!=nterm_id.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }

    fclose(stdout);

}

//读入产生式
void Init() {
    int term_cnt = 0, nterm_cnt = 0;
    int n, m;
    string nterm, tmp;

    freopen("in", "r", stdin);

    nterm_id.clear();
    term_id.clear();

    while (cin >> n >> nterm) {
        nterm_id[nterm] = nterm_cnt++;

        while (n--) {
            cin >> m;
            while (m--) {
                cin >> tmp;
                if (tmp[0] >= 'a' && tmp[0] <= 'z') continue;
                if (term_id.find(tmp) == term_id.end()) {
                    term_id[tmp] = term_cnt++;
                    //cout << tmp << " " << term_cnt << endl;
                }
            }
        }
    }

    //cout << nterm_cnt << endl;
    //cout << term_cnt << endl;

    fclose(stdin);




    freopen("in", "r", stdin);

    nterm_prod.clear();
    prod.clear();

    while (cin >> n >> nterm) {
        vector<int> nterm_prod_l; //非终结符对应的产生式 内容

        while (n--) {
            //读入nterm对应的n个产生式
            cin >> m;
            prod_t p;

            p.nterm = nterm_id[nterm];
            while (m--) {
                cin >> tmp;
                if (tmp[0] >= 'a' && tmp[0] <= 'z') {
                    p.sym_list.push_back(sym_t(false, nterm_id[tmp]));
                } else {
                    p.sym_list.push_back(sym_t(true, term_id[tmp]));
                }
            }
            nterm_prod_l.push_back(prod.size());
            prod.push_back(p);
        }
        nterm_prod.push_back(nterm_prod_l);
    }

    fclose(stdin);

    print_info();
}



//状态生成
void Generate_state() {
    state_t start;
    prodd p;

    int idx = term_id["start"];
    p.prod_id = nterm_prod[idx][0];
    p.dot = 0;
    p.pre.clear(); p.pre.push_back('#'); //加入输入结束符

    //生成初始状态
    start.prod.push_back(p);

}



//当前状态的闭包
void closure(state_t s) {
    queue<prod_t> Q;

}


//对于 [A->a.Bw, b] 生成 wb 的FIRST集
void FIRST(vector<sym_t> &sl) {

}







