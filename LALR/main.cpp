#include <string>
#include <algorithm>
#include <iostream>
#include <map>
#include <set>

#include <cstdio>
#include <cstring>
#include "lex.h"


using namespace std;

set<string> sset;

int main() {

    freopen("Grammar", "r", stdin);
    freopen("Table", "w", stdout);


    sset.clear();
    while (next_word()) {
        if (sset.find(buffer) == sset.end()) {
            sset.insert(buffer);
        }
    }

    for (set<string>::iterator it=sset.begin(); it!=sset.end(); it++) {
        cout << *it << endl;
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
