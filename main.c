#include <stdio.h>
#include "./Chapter5/chapter5.h"

int main() {
    int a[8];

    int *b = basic_memset(a, -1, 32);

    for (int i = 0; i < 8; ++i) {
        printf("%d\n", a[i]);
    }
    return 0;
}