//
// Created by Apoiuty on 2019/9/5.
//

#include "chapter2.h"
#include <stdio.h>
#include <stdint.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>


void show_bytes(unsigned char *start, size_t len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%.2x", start[i]);
    }
    printf("\n");
}

int is_little_endian() {
    int32_t x = 0x12345678;
    unsigned char *start = (char *) &x;
    if (*start == 0x12)
        return 0;
    else if (*start == 0x78)
        return 1;
}

unsigned replace_byte(unsigned x, int i, int b) {
    return (x & ~(0xFF << 8 * i)) | b << 8 * i;
}

int func262(int x) {
    unsigned w = sizeof(x) << 3;
    return !(~x) || !x || !(~(x | ~0xFF)) || !(x & (0xFF << (w - 8)));
}

int int_shift_are_arithmetic() {
    return (INT_MIN >> 1) < 0;
}

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    unsigned w = sizeof(int) << 3;
    return xsra & ~(-1 << (w - k));
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    unsigned w = sizeof(int) << 3;
    return xsrl < 0 ? xsrl | ~(-1 << (w - k)) : xsrl;
}

int odd_ones(unsigned x) {
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;
    return x & 1;
}

int left_most(unsigned x) {
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return x & (~x >> 1);
}

int low_one_mask(int n, int w) {
    return ~(INT_MIN >> (w - n - 1));
}

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    return x << n | x >> (w - n - 1) >> 1;
}

int fit_bits(int x, int n) {
    x >>= n - 1;
    return !(x >> 1) || !~x;
}

int xbyte(unsigned x, int bytenum) {
    return (int) (int8_t) ((x >> (bytenum << 3)) & 0xff);
}

int saturate_add(int x, int y) {
    int mask = INT_MIN;
    int sum = x + y;
    int pos_overflow = !(x & mask) && !(y & mask) && (sum & mask);
    int neg_overflow = (x & mask) && (y & mask) && !(sum & mask);
    (pos_overflow && (sum = INT_MAX)) || (neg_overflow && (sum = INT_MIN));
    return sum;
}

int signed_high_prob(int x, int y) {
    int64_t mul = (int64_t) x * y;
    return mul >> 32;
}

unsigned unsigned_high_prob(unsigned x, unsigned y) {
    uint64_t mul = (uint64_t) x * y;
    return mul >> 32;
}

void *my_calloc(size_t nmemb, int size) {
    if (!nmemb || !size)
        return NULL;


    size_t Size = nmemb * size;
    if (Size / nmemb != size)
//        如何检验乘法是否溢出
        return NULL;
    else {
        void *p = (void *) malloc(Size);
        memset(p, 0, Size);
        return p;
    }
}

int divide_power2(int x, int k) {
    return (x + (1 << k) - 1) >> k;
}

int mul3div4(int x) {
    int temp = (x + (1 << 2) - 1) >> 2;
    return temp * 3;
}

int threefourths(int x) {
    int is_neg = x & INT_MIN;
    int low2 = x & 0x3;
    int high30 = x & ~0x3;
    high30 = high30 >> 2;
    high30 = (high30 << 1) + high30;
    low2 = (low2 << 1) + low2;
    is_neg && (low2 = low2 + (1 << 2) - 1);
    low2 >>= 2;
    return high30 + low2;
}

float fpwr(int x) {
    unsigned frac, exp, u;
    /*result exponent and fraction*/

    if (x < -149) {
        exp = 0;
        frac = 0;
//        太小
    } else if (x < -126) {
//        非规格化浮点数
        exp = 0;
        frac = 1 << (23 - (-126 - x));
    } else if (x < 128) {
//        规格化浮点数
        exp = x + (1 << 7) - 1;
        frac = 0;
    } else {
//        正无穷
        exp = 0xFF;
        frac = 0;
    }
    u = exp << 23 | frac;
    return u2f(u);
}

float u2f(unsigned int u) {
//    如何将一种数据类型解释为另一种数据类型
    return *(float *) &u;
}
