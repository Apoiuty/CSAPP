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
    int i;
    for (i = len-1; i >=0; i--) {
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
    return ((unsigned) -1 >> (w - n));
}

unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(int) << 3;
    return x << n | x >> (w - n - 1) >> 1;
}

int fit_bits(int x, int n) {
    return !x || !(x >> (n - 1) >> 1);
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
    int result = x >> k;
    (x & INT_MIN) && (result = (x + (1 << k) - 1) >> k);
    return result;
}

int mul3div4(int x) {
    int temp = (x + (1 << 2) - 1) >> 2;
    return temp * 3;
}

int threefourths(int x) {
    //要先算除法再算乘法
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

int any_odd_ones(unsigned x) {
    return x & 0x55555555;
}

int tsub_ok(int x, int y) {
    int result = 1;
    int mask = INT_MIN;
    !(y ^ INT_MIN) && !(x & INT_MIN) && (result = 0);

    y = -y;
    int sum = x + y;
    int pos_overflow = (y ^ INT_MIN) && !(x & mask) && !(y & mask) && (sum & mask);
    int neg_overflow = (y ^ INT_MIN) && (x & mask) && (y & mask) && !(sum & mask);
    (pos_overflow && (result = 0)) || (neg_overflow && (result = 0));
    return result;
}

int float_le(float x, float y) {
    unsigned ux = f2u(x);
    unsigned uy = f2u(y);
    unsigned sx = ux >> 31, sy = uy >> 31;
    return (sx && !sy) || (!sx && !sy && ux <= uy) || (sx && sy && ux >= uy);
}

unsigned f2u(float f) {
    return *(unsigned *) &f;
}

float float_negate(float f) {
    unsigned F = *(unsigned *) &f;
    unsigned sign = F >> 31;
    unsigned exp = F >> 23 & 0xff;
    unsigned frac = F & 0x7fffff;
    if (sign == 1 && exp == 0xff && frac) {
        return f;
    } else {
        F = F ^ INT_MIN;
        return *(float *) &(F);
    }


}

float float_twice(float f) {
    unsigned F = *(unsigned *) &f;
    unsigned sign = F >> 31;
    unsigned exp = F >> 23 & 0xff;
    unsigned frac = F & 0x7fffff;

    if (sign == 1 && exp == 0xff && frac) {
        return f;
    } else {
        if (exp == 0) {
            frac <<= 1;
        } else if (exp == 0xFF - 1) {
            exp = 0xFF;
            frac = 0;
        } else {
            exp += 1;
        }
        F = sign << 31 | exp << 23 | frac;
        return *(float *) &F;
    }

}

int f2i(float f) {
    unsigned F = *(unsigned *) &f;
    unsigned sign = F >> 31;
    unsigned exp = F >> 23 & 0xff;
    unsigned frac = F & 0x7fffff;
    frac |= 0x800000;

    uint64_t Frac = frac;
    int result;
    int E = exp;
    E -= 127 + 23;
    if (E >= 0 && E < 128) {
        Frac = Frac << E;
        if (Frac == frac << E && !((frac << E) & INT_MIN)) {
            result = Frac;
            return sign ? -result : result;
        } else {
            return 0x80000000;
        }
    } else if (E > -24 && E < 0) {
        E = -E;
        frac >>= E;
        result = frac;
        return sign == 1 ? -result : result;
    } else {
        if (E == 128) {
            return 0x80000000;
        } else
            return 0;
    }
}

float i2f(int i) {
    unsigned frac;
    unsigned sign = 0;
    int exp;


    if (i < 0) {
//    if i is INT_MIN
        sign = 1;
        if (i == INT_MIN) {
            frac = INT_MAX;
            frac++;
        } else {
            frac = -i;
        }
    } else
        frac = i;


    int first_one;
    unsigned mask = INT_MIN;
    for (first_one = 31; first_one >= 0; --first_one) {
        if (mask & frac) {
            break;
        }
        mask >>= 1;
    }

    if (first_one < 0) {
        return 0;
    } else if (first_one <= 23) {
        exp = first_one;
        frac = frac << 23 - first_one;
    } else if (first_one > 23) {
        exp = first_one;

//        round to even
        int last_bit = (frac >> first_one - 23) & 1;
        int cut_off = frac & (~(INT_MIN >> 54 - first_one));
        if ((cut_off == 1 << first_one - 24) && last_bit == 1) {
            frac >>= first_one - 23;
            frac--;
        } else if (cut_off > 1 << first_one - 24) {
            frac =frac>>first_one - 23;
            if ((frac >> 23) != (frac + 1 >> 23)) {
                frac++;
                frac>>=1;
                exp++;
            }
        } else
            frac >>= first_one - 23;
    }

    exp += 127;

    unsigned F = sign << 31 | exp << 23 | frac & 0x7fffff;

    return *(float *) &F;

}
