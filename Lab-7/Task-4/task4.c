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

    struct sigaction catch;
    catch.sa_handler = handler;
    sigemptyset(&catch.sa_mask);
    catch.sa_flags = 0;

    int status, cKill;
    pid_t  pid1, pid2;
    
    pid1 = fork();
    switch(pid1){
        case -1:
            puts("Error Forking");
            return -1;
        case 0:
            kill(pid1, SIGUSR1);
            break;
        default:
            pid2 = fork();
            switch(pid2){
                case -1:
                    puts("Error Forking");
                    return -1;
                    break;
                case 0:
                    //Second Child waiting for First Child to finish
                    //cKill = waitpid(pid1, &status, WUNTRACED);
                    kill(pid2, SIGUSR2);
                    break;
                default:
                    sigaction(SIGUSR1, &catch, NULL);
                    pause();
                    sigaction(SIGUSR2, &catch, NULL);
                    pause();
                    exit(0);
                    break;
            }
    }
    return 0;
}
