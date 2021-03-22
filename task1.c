#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    pid_t pid1;
    pid_t pid2;
    pid1 = fork();
    switch(pid1){
        case -1:
            puts("ERROR FORKING");
            exit(1);
        case 0:
            pid2 = fork();
            switch(pid2){
                case -1:
                    puts("ERROR FORKING");
                    exit(1);
                case 0:
                    while(1){
                        if(getppid() == 1){
                            _exit(0);
                        }
                        puts("I am your grandchild");
                        sleep(1);
                    }
                    break;
                default:
                    for(int i=0; i<3; i++){
                        puts("I am your child");
                        sleep(1);
                    }   
                    _exit(0);
            }
    }
    int stat;
    pid_t ID;
    while(1){
        ID = waitpid(pid1, &stat, WNOHANG|WUNTRACED);
        if(ID == 0){
            puts("I am your parent");
            sleep(1);
        }else{
            puts("I finish my job");
            exit(0);
        }

    }
}
