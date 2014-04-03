#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include "lib.h"
using namespace std;

vector<string> term_list;
vector<string> nterm_list;

map<string, vector<prod_t> > nterm_prod; //非终结符对应的产生式



/*
    nterm ::
        production_1
        production_2
        ....
        production_m
    将每个产生式展开为 扩展形式
        nterm ::= a.Bc
*/
static void get_prod (string &nterm, int c) {
    int m;
    prod_t prod;
    sym_t  symbol;
    string tmp;
    vector<prod_t> prod_l;

    while (c--) {
        cin >> m;

        prod.sym_list.clear();

        for (int i=0; i<m; i++) {
            cin >> symbol.sym;

            if (symbol.sym[0] >= 'a' && symbol.sym[0] <= 'z') {
                symbol.is_term = false;
            } else {
                symbol.is_term = true;
            }
            prod.sym_list.push_back(symbol);
        }

        for (int i=0; i<=m; i++) {
            prod.dot = i;
            prod_l.push_back(prod);
        }
    }

    nterm_prod.insert(make_pair(nterm, prod_l));
}
void closure() {

}
void Init() {
    int n;
    string nterm, term;

    nterm_prod.clear();
    term_list.clear();
    nterm_list.clear();

    while (cin >> n >> nterm) {
        nterm_list.push_back(nterm);

        get_prod(nterm, n);
    }
}





