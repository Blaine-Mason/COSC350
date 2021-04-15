#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>

void handler(int sig){
	if(sig==SIGUSR1){
		printf("I am terminated by my parent\n");
        kill(getppid(), SIGUSR2);
        _exit(0);
    }
    if(sig == SIGUSR2){
        printf("My child is gone so I don't need to stay\n");
        _exit(0);
    }
}

int main(){
	pid_t pid;
	pid=fork();
	
	switch(pid){
        case 0:
            while(1){
                signal(SIGUSR1,handler);
                printf("child is running\n");
                sleep(1);
            }
		default:
            while(1)
            {
                signal(SIGUSR2, handler);  
                for(int i = 0; i < 10; i++){
                    printf("parent is running\n");
                    sleep(1);
                }
                kill(pid, SIGUSR1);
            }
            wait(NULL);
            exit(0);

    }
	return 0;
}
