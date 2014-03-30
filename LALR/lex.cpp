#include <stdio.h>
#include <string.h>
#include "lex.h"

char buffer[MAXLINE];

int next_word() {

    while (scanf(" %s", buffer) == 1) {
        if (buffer[0] == '#') continue;

        if (strlen(buffer) < 4) continue;
        return 1;
    }
    return 0;
}
