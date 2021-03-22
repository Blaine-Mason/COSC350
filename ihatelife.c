#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    pid_t pid;
    pid_t pid2;
    pid = fork();
    switch(pid) {
        case -1: //error
            perror("fork error");
            exit(1);
        case 0: //child
            pid2 = fork();
            switch(pid2) {
                
                case -1: //error
                    perror("fork error");
                    exit(1);
                
                case 0: //grandchild
                    while(1){
                        if(getppid() == 1){ //orphaned process new parent
                            _exit(0);
                        }
                        printf("I am your grandchild\n");
                        sleep(1);
                    }
                    break;
                default: //child
                    for(int i=0; i<4; i++) {
                        printf("I am your child\n");
                        sleep(1);
                    }
                    _exit(0);
            }
    }

    int status;
    pid_t endID; 
    while(1){
        endID = waitpid(pid, &status, WNOHANG|WUNTRACED);
        if(endID == 0){ //child still running
            printf("I am your parent\n");
            sleep(1);
        }else{
            printf("I finish my job\n");
            exit(0);
        }
    }
}