//
// Created by Apoiuty on 2020/4/6.
//

#include "chapter5.h"
#include <stdio.h>


void inner(int *u, int *v, int *dest, int len) {
    long i;
    int sum1, sum2, sum3, sum4, sum5, sum6;
    sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0, sum6 = 0;

    for (i = 0; i < len - 6 + 1; i += 6) {
        sum1 += v[i] * u[i];
        sum2 += v[i + 1] * u[i + 1];
        sum3 += v[i + 2] * u[i + 2];
        sum4 += v[i + 3] * u[i + 3];
        sum5 += v[i + 4] * u[i + 4];
        sum6 += v[i + 5] * u[i + 5];
    }

    int sum = sum1 + sum2 + sum3 + sum4 + sum5 + sum6;

    for (; i < len; ++i) {
        sum += u[i] * v[i];
    }

    *dest = sum;
}


void inner16(int *u, int *v, int *dest, int len) {
    long i;
    int sum1;

    for (i = 0; i < len - 6 + 1; i += 6) {
        sum1 += (v[i] * u[i] + v[i + 1] * u[i + 1] + v[i + 2] * u[i + 2] + u[i + 3] * v[i + 3] + u[i + 4] * v[i + 4] +
                 v[i + 5] * u[i + 5]);
    }

    for (; i < len; ++i) {
        sum1 += u[i] * v[i];
    }

    *dest = sum1;
}

void *basic_memset(void *s, int c, size_t n) {
    size_t cnt = 0;
    unsigned char *src = s;

    unsigned long set_value = 0;
    for (int i = 0; i < 4; ++i) {
        set_value = (set_value << 8) | (unsigned) c;
    }

    while (cnt % 4 && cnt < n) {
        *src++ = (unsigned char) c;
        cnt++;
    }

    while (cnt + 4 < n) {
        *((unsigned long *) src) = set_value;
        cnt += 4;
        src += 4;
    }

    while (cnt < n) {
        *src = (unsigned char) c;
        cnt++;
        src++;
    }

    return s;
}

void psum(float *a, float *p, long n) {
    p[0] = a[0];
    float last_re = p[0];
    int j;
    for (j = 1; j < n - 1; j+=2) {
        p[j] = last_re + a[j];
        p[j + 1] = (last_re + a[j]) + a[j + 1];
        last_re = (last_re + a[j]) + a[j + 1];
    }

    while (j < n) {
        p[j] = last_re + a[j];
        j++;
    }

}
