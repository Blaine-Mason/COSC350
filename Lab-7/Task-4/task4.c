#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>

void handler(int sig){
	if(sig==SIGUSR1)
		printf("Hi Honey! Anything wrong?\n");
	
	if(sig==SIGUSR2)
		printf("Do you make trouble again?\n");
}

int main(int argc, char** argv){
	
	pid_t pid,pid2;
	signal(SIGUSR1,handler);	
	signal(SIGUSR2,handler);
	
	pid=fork();
	
	switch(pid){
        case 0:
			kill(getppid(),SIGUSR1);
			exit(0);
		default:
		    waitpid(pid,NULL,0);
		    pid2=fork();
		    switch(pid2){
                case 0:
			        kill(getppid(),SIGUSR2);	
			        exit(0);
                default:
		            waitpid(pid2,NULL,0);	
		    }
    }
	return 0;
}
