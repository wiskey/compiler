#include <stdio.h>
#include <stdlib.h>
#include "token.h"

token_t in_token;

int main()
{

    freopen("test.c", "r", stdin);

    while ((in_token = next_token()) != END) {
        printf("%10s\t%d\n", buffer, in_token);
    }


    return 0;
}
