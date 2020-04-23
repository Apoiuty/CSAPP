//
// Created by Apoiuty on 2020/4/14.
//

#ifndef CSAPP_CHAPTER8_H
#define CSAPP_CHAPTER8_H

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "csapp.h"
#include <setjmp.h>

jmp_buf buf;
/*
 * 8.11
 */
void fork811();

/// 8.22
/// \param cmd
/// \return
int mysystem(char *cmd);


/// 8.25
/// \param string
/// \param n
/// \param stream
/// \return
char *tfgets(char *string, int n, FILE *stream);

/// 8.25 handler
/// \param sig
void handler(int sig);
#endif //CSAPP_CHAPTER8_H
