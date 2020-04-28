//
// Created by Apoiuty on 2020/2/10.
//

#include "chapter3.h"

long decode2(long x, long y, long z) {
    long tmp= y - z;
    x = x * tmp;
    return ((tmp << 63) >> 63) ^ x;
}


long loop(long x, int n) {
    long re = 0;
    long mask;
    for (mask = 1; mask != 0; mask <<= n) {
        re |= x & mask;
    }
    return mask;
}

long cread_alt(long *xp) {
    return !xp ? 0 : *xp;
}

long switch3(long *p1, long *p2, mode_t action) {
    long result = 0;

    switch (action) {
        case A:
            result = *p2;
            *p2 = *p1;
            break;
        case B:
            result = *p1 + *p2;
            *p1 = result;
            break;
        case C:
            *p1 = 59;
            result = *p2;
            break;
        case D:
            *p1 = *p2;
            result = 27;
            break;
        default:
            result = 12;
    }

    return result;
}

long switch_prob(long x, long n) {
    long r = x;
    switch (n) {
        case 60:
        case 62:
            r = 8 * x;
            break;
        case 3:
            r = x >> 3;
            break;
        case 4:
            r = x;
            r <<= 4;
            r -= x;
            x = r;
        case 5:
            x = x * x;
        default:
            r = x + 0x4b;
    }
    return r;
}

void test(long i, b_strcut *bp) {
    int n=bp->first+bp->last;
    a_struct *ap = &bp->a[i];
    ap->x[ap->idx] = n;
}

int find_range(float x) {
    return 0;
}
