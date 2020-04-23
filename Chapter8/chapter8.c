//
// Created by Apoiuty on 2020/4/14.
//

#include "chapter8.h"

void fork811() {
    for (int i = 0; i < 2; ++i) { ;
    }
    printf("Hello\n");
    exit(0);
}

int mysystem(char *cmd) {
    int state;
    if (*cmd) {
        pid_t pid;
        if ((pid = Fork()) == 0) {
            char *argv[4] = {"", "-c", cmd, NULL};
            execve("\bin\sh", argv, environ);
        } else {
            printf("pid number is %d", pid);
        }

        if (Waitpid(pid, &state, 0) > 0) {
            if (WIFEXITED(status))
                return WEXITSTATUS(status);
            /* exit by signal */
            if (WIFSIGNALED(status))
                return WTERMSIG(status);
        }
    }
}

char *tfgets(char *string, int n, FILE *stream) {
    pid_t pid;

    if (!setjmp(buf)) {
        Alarm(5);
        if (signal(SIGALRM, handler) == SIG_ERR) {
            unix_error("set alarm handler erro");
        }

        return fgets(string, n, stream);
    } else {
        return NULL;
    }
}

void handler(int sig) {
    longjmp(buf, 1);
}

