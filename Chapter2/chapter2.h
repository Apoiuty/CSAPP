//
// Created by Apoiuty on 2019/9/5.
//

#include <stddef.h>

#ifndef CSAPP_CHAPTER2_H
#define CSAPP_CHAPTER2_H
void show_bytes(unsigned char *start, size_t len);
//打印程序对象的字节表示

int is_little_endian();
//判断是大端机器还是小端机器

unsigned replace_byte(unsigned x, int i, int b);
//参数x的i字节被替换为b

int func262(int x);

int int_shift_are_arithmetic();
//判断是逻辑右移还是算数右移

unsigned srl(unsigned x, int k);
//算数移位完成算数移位

int sra(int x, int k);
//逻辑移位完成算数移位

/**
 * 存在奇数位上有1
 */
int any_odd_ones(unsigned x);


int odd_ones(unsigned x);
//x有奇数个1时返回1

int left_most(unsigned x);
//generate mask indicating leftmost 1 in x.

int low_one_mask(int n, int w);
//mask the least significant n bits set to 1.

unsigned rotate_left(unsigned x, int n);
//循环左移

int fit_bits(int x, int n);
//x是否可以用n位补码表示

int xbyte(unsigned x, int bytenum);
//返回无符号数x的bytenum字节表示

int saturate_add(int x, int y);
//饱和运算

/**
 * x-y是否溢出
 * @param x
 * @param y
 * @return 溢出返回0,不溢出返回1
 */
int tsub_ok(int x,int y);

int signed_high_prob(int x, int y);

unsigned unsigned_high_prob(unsigned x, unsigned y);

void *my_calloc(size_t nmemb, int size);

int divide_power2(int x, int k);
//Divide vy power of 2. 0<=k<=w-1.

int mul3div4(int x);

/**
 * x是否小于y
 * @param x
 * @param y
 * @return 小于返回1
 */
int  float_le(float x, float y);

/**
 * 将float转化为unsigned
 * @param f
 * @return
 */
unsigned f2u(float f);

int threefourths(int x);

float fpwr(int x);

float u2f(unsigned int u);

/**
 * return the negative value of f
 * @param f
 * @return
 */
float float_negate(float f);

/**
 * return 2*f if f isn't nan
 * @param f
 * @return
 */
float float_twice(float f);

/**
 * convert float 2 int
 * @param f
 * @return
 */
int f2i(float f);

/**
 * convert int 2 float
 * @param i
 * @return
 */
float i2f(int i);


#endif //CSAPP_CHAPTER2_H
