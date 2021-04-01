#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handler(int sig){
    if(sig == SIGUSR1){
        puts("Hi Honey! Anything wrong?");
    }else if(sig == SIGUSR2){
        puts("Do you make trouble again?");
    }
}

int main(){
    pid_t  pid1, pid2;

    pid1 = fork();
    switch(pid1){
        case -1:
            puts("Error Forking");
            return -1;
        case 0:
            kill(getppid(), SIGUSR1);
            _exit(0);
            break;
        default:
            pid2 = fork();
            switch(pid2){
                case -1:
                    puts("Error Forking");
                    return -1;
                case 0:
                    //Second Child waiting for First Child to finish
                    kill(getppid(), SIGUSR2);
                    _exit(0);
                    break;
                default:
                    signal(SIGUSR1, handler);
                    signal(SIGUSR2, handler);
                    pause();
                    pause();
                    _exit(0);
            }
    }
    return 0;
}
