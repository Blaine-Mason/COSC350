#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>

void handler(int sig){
	if(sig==SIGUSR1){
		printf("From now on, I am zombie\n");
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
                printf("I am your child\n");
                sleep(1);
            }
		default:
            while(1)
            {  
                for(int i = 0; i < 10; i++){
                    printf("I am your parent\n");
                    sleep(1);
                }
                kill(pid, SIGUSR1);
            }
            exit(0);
    }
	return 0;
}
