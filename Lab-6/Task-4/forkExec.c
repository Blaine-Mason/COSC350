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
            printf("Exec of child.c: %d\n", execlp("./child", message, argv[1], argv[3], (char *)0));
            break;
        default:
            message = "This is the parent";
            n = new_atoi(argv[2]);
            time = new_atoi(argv[4]);
            break;
    }
    for(; n > 0; n--) {
        printf("%s pid: %d\n", message, pid);
        sleep(time);
        if(pid != 0){
            puts("Waiting for child process to finish.\n");
            wait(0);
            puts("Child process done.\n");
        }
    }
    exit(0);
}
