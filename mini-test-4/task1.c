#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>

void handler(int sig){
	if(sig==SIGUSR1){
		printf("I am terminated by my parent\n");
        exit(0);
    }
}

int main(){
	pid_t pid,pid2;
	signal(SIGUSR1,handler);	
	signal(SIGUSR2,handler);
	
	pid=fork();
	
	switch(pid){
        case 0:
            signal(SIGUSR1,handler);
            while(1){
                printf("child is running\n");
                sleep(1);
            }
		default:
            for (int i = 0; i < 10; i++)
            {
                printf("parent is running\n");
                sleep(1);
            }
            kill(pid, SIGUSR1);
            wait(NULL);
            printf("My child is gone so I don't need to stay\n");
            exit(0);

    }
	return 0;
}