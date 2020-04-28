//
// Created by Apoiuty on 2020/4/25.
//

#ifndef CSAPP_CHAPTER9_H
#define CSAPP_CHAPTER9_H

#include <stdio.h>

#define WSIZE 4
#define DSIZE 8

#define PACK(size, alloc) ((size)|(alloc))
#define GET(p) (*(unsigned int *)(p))
#define PUT(p, val) (*(unsigned *)(p))
#define GETSIZE(p) (GET(p)&~0x7)
#define GET_ALLOC(p) (GET(p)&0x1)

#define HDPR(bp) ((char *)(bp) - WSIZE)
#define FTPR(bp) ((char *)(bp)+GETSIZE(HDPR(bp))-DSIZE)

#define NEXT_BP(bp) ((char *)(bp) +GETSIZE(((char *)(bp)-WSIZE)))
#define PREV_BP(bp) ((char *)(bp) WGETSIZE(((char *)(bp)-DSIZE)))

/// 9.8
/// \param asize
/// \return
static void *find_fit(size_t asize);

#endif //CSAPP_CHAPTER9_H
