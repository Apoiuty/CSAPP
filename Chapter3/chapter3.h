//
// Created by Apoiuty on 2020/2/10.
//

#ifndef CSAPP_CHAPTER3_H
#define CSAPP_CHAPTER3_H

typedef struct {
    long idx;
    long x[4];
}a_struct;

typedef struct {
    int first;
    a_struct a[7];
    int last;
}b_strcut;

/**
 * 3.69
 * @param i
 * @param bp
 */
void test(long i,b_strcut *bp);

/**
 * 3.58
 * @param x
 * @param y
 * @param z
 * @return
 */
long decode2(long x,long y,long z);

/**
 * 3.60
 * @param x
 * @param n
 * @return
 */
long loop(long x,int n);

/**
 * 3.61
 * @param xp
 * @return
 */
long  cread_alt(long *xp);

typedef enum {A , B, C, D, E} mode_t;

/**
 * 3.62
 * @param p1
 * @param p2
 * @param action
 * @return
 */
long switch3(long *p1,long *p2,mode_t action);

/**
 * 3.63
 * @param x
 * @param n
 * @return
 */
long switch_prob(long x,long n);

/**
 * 3.73
 * @param x
 * @return
 */
int find_range(float x);


#endif //CSAPP_CHAPTER3_H
