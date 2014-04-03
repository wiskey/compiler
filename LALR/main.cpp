#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include "lib.h"


using namespace std;

void print(const string &nterm, prod_t &p) {
    cout << nterm << "=>";

    for (size_t i=0; i<p.sym_list.size(); i++) {
        if (p.dot == (int)i) cout << " .";
        sym_t &x = p.sym_list[i];
        cout << " " << x.sym;
    }
    if (p.dot == (int)p.sym_list.size()) cout << " .";
    cout << endl;
}
int main() {

    freopen("in", "r", stdin);
    freopen("Table", "w", stdout);

    Init();


    for (map<string, vector<prod_t> >::iterator it=nterm_prod.begin();
                it != nterm_prod.end(); it++) {

        for (size_t i=0; i<(it->second).size(); i++)
            print(it->first, (it->second)[i]);
    }


    fclose(stdin);
    fclose(stdout);
    return 0;
}
