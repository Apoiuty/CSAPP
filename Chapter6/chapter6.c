//
// Created by Apoiuty on 2020/4/9.
//

#include "chapter6.h"

int transpose(int *des, int *src, int dim) {
    int a, b;
    int i = 0;
    int j = 0;
    for (; i <= dim - BLOCK; i += BLOCK) {
        for (; j <= dim - BLOCK; j += BLOCK) {

            for (a = i; a < i + BLOCK; i++) {
                for (b = j; b < j + BLOCK; j++) {
                    des[b * dim + a] = src[a * dim + b];
                }
            }
        }
    }

    for (; i <= dim - 1; i++)
        for (; j <= dim - 1; j++)
            des[j * dim + i] = src[i * dim + j];
}

void col_convert(int *G, int dim) {

    int a, b;
    int i = 0;
    int j = 0;
    int temp;
    for (; i <= dim - BLOCK; i += BLOCK) {
        for (; j <= dim - BLOCK; j += BLOCK) {

            for (a = i; a < i + BLOCK; i++) {
                for (b = j; b < j + BLOCK; j++) {
                    temp = G[b * dim + a] || G[a * dim + b];
                    G[b * dim + a] = G[a * dim + b] = temp;
                }
            }
        }
    }

    for (; i <= dim - 1; i++)
        for (; j <= dim - 1; j++)
            G[j * dim + i] = G[i * dim + j] || G[j * dim + i];
}
