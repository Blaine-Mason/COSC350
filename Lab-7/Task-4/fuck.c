#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>// open
#include<string.h>
#include<sys/wait.h>// wait
#include<sys/stat.h>// umask
#include<signal.h>

void parrent(int SIG){
    if(SIG == SIGUSR1){
        printf("Hi honey, anything wrong?\n");
    }else if(SIG == SIGUSR2){
        printf("Do you make trouble again?\n");
    }
}
int main(){
    pid_t pid, pid2;
    pid = fork();
    if(pid == 0){//child 1
        kill(getppid(), SIGUSR1);
        _exit(0);
    }else{//parrent
        pid2 = fork();
        if(pid2 == 0){
            kill(getppid(), SIGUSR2);
            _exit(0);
        }else{
            signal(SIGUSR1, parrent);
            signal(SIGUSR2, parrent);
            pause();
            pause();
        }
    }
    return(0);
}
