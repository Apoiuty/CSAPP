//
// Created by Apoiuty on 2020/4/9.
//

#ifndef CSAPP_CHAPTER6_H
#define CSAPP_CHAPTER6_H

#define BLOCK 16
/**
 * 6.45
 * @param des
 * @param src
 * @param dim
 * @return
 */
int transpose(int *des,int *src,int dim);

/**
 * 6.46
 * @param G
 * @param dim
 */
void col_convert(int *G,int dim);

#endif //CSAPP_CHAPTER6_H
