#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int new_atoi(char* str){
    int ret = 0, i = 0, neg = 0;
    if(str[0] == '-'){
        neg = 1;
        i++;
    }
    for(; str[i] != '\0'; ++i){
        ret = ret * 10 + (str[i] - '0');
    }
    if(neg){
        return ret*(-1);
    }else{
        return ret;
    }
}
//This task instead uses the wait function to handle
//the termination of processes
//So they will execute in order 
int main(int argc, char* argv[]){
    pid_t pid;
    char *message;
    int n, time;
    printf("Fork program starting\n");
    pid = fork();
    switch(pid){
        case -1:
            perror("fork failed");
            exit(1);
        case 0:
            message = "This is the child";
            n = new_atoi(argv[1]);
            time = new_atoi(argv[3]);
            break;
        default:
            message = "This is the parent";
            n = new_atoi(argv[2]);
            time = new_atoi(argv[4]);
            break;
    }
    if (pid != 0) {
        int stat_val;
        pid_t child_pid;
        child_pid = wait(&stat_val);
    
        printf("Child has finished: PID = %d\n", child_pid);
        if(WIFEXITED(stat_val))
            printf("Child exited with code %d\n", WEXITSTATUS(stat_val));
        else
            printf("Child terminated abnormally\n");
    }
    for(; n > 0; n--) {
        puts(message);
        sleep(time);
    }
    exit(0);
}
