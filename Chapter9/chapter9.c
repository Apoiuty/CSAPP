//
// Created by Apoiuty on 2020/4/25.
//

#include <stddef.h>
#include <sys/stat.h>
#include <strmif.h>
#include "chapter9.h"

static void *find_fit(size_t asize) {
    extern char *last_listp;
    char *bp = NEXT_BP(last_listp);
    if (!GETSIZE(bp)) {
        extern char *listp;
        bp = listp;
    }

    // todo:nothing to do
    char *next_bp;
    unsigned old_size;
    while (GETSIZE(HDPR(bp))) {
        if (!GET_ALLOC(bp)) {
            old_size = GETSIZE(HDPR(bp));

            if (old_size >= asize + 2 * DSIZE) {
                PUT(HDPR(bp), PACK(asize, 1));
                PUT(FTPR(bp), PACK(asize, 1));
                next_bp = bp + asize;
                PUT(HDPR(next_bp), PACK(old_size - asize, 1));
                PUT(FTPR(next_bp), PACK(old_size - asize, 1));

                return bp;
            } else if (old_size > asize) {
                PUT(HDPR(bp), PACK(asize, 1));
                PUT(FTPR(bp), PACK(asize, 1));

                return bp;
            }
        }
    }

    return NULL;
}



