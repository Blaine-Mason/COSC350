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
    int n;
    pid = getpid();
    n = new_atoi(argv[1]);
    for(; n > 0; n--) {
        printf("%s PID: %d\n", argv[0], pid);
        sleep(new_atoi(argv[2]));
    }
    exit(37);
}

