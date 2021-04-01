#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void handler(int sig) {
	signal(SIGQUIT, SIG_DFL);
}

int main() {
    sigset_t mask, mask2, OG_mask;
    
    sigemptyset(&mask);
    sigemptyset(&mask2);

    sigaddset(&mask, SIGINT);
    sigaddset(&mask2, SIGQUIT);

    sigprocmask(SIG_BLOCK, &mask, &OG_mask);
    sigprocmask(SIG_BLOCK, &mask2, &OG_mask);

    for(int i = 1; i <= 5; i++){
        printf("%d\n", i);
        sleep(1);
    }

    signal(SIGQUIT, handler);
    signal(SIGINT, handler);

    sigprocmask(SIG_UNBLOCK, &mask2, &OG_mask);

    sigaddset(&mask, SIGINT);
    sigaddset(&mask2, SIGQUIT);

    sigprocmask(SIG_BLOCK, &mask, &OG_mask);
    for(int i = 1; i <= 5; i++){
        printf("%d\n", i);
        sleep(1);
    }

    exit(0);
}
