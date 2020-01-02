#include <stdio.h>
#include "./Chapter2/chapter2.h"
#include <limits.h>

int main() {
    int x = 25, y = -89;
    unsigned a = x, b = y;
    int i = 0x40490fdb;
    float f = *(float *) &i;
    printf("%f %f", i2f(INT_MIN), (float) INT_MIN);
    f=INT_MIN;

    printf("\n");
    printf("%f\n", f);
    show_bytes(&f, sizeof(float));

}