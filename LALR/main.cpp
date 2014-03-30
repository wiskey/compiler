#include <cstdio>
#include <cstring>
#include "lex.h"

int main() {

    freopen("Grammar", "r", stdin);
    freopen("Table", "w", stdout);


    while (next_word()) {
        printf("%s\n", buffer);
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
