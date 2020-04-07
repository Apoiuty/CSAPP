//
// Created by Apoiuty on 2020/4/6.
//

#include <stddef.h>

#ifndef CSAPP_CHAPTER5_H
#define CSAPP_CHAPTER5_H

/**
 * 5.15
 * @param u
 * @param v
 * @param dest
 */
void inner(int *u, int *v, int *dest, int len);

/**
 * 5.16
 * @param u
 * @param v
 * @param dest
 * @param len
 */
void inner16(int *u, int *v, int *dest, int len);

void *basic_memset(void *s, int c,
                   size_t n);

/**
 * 5.19
 * @param a
 * @param p
 * @param n
 */
void psum(float a[], float p[],long n);

#endif //CSAPP_CHAPTER5_H
