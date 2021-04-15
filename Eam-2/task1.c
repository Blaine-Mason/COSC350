#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    pid_t pid;
    int fd1[2]; //c -> p
    int fd2[2]; //p -> c
    //[0] -> READ
    //[1] -> WRITE
    pipe(fd1);
    pipe(fd2);
    
    pid = fork();
    
    
    if(pid == 0){
        char* msg = "Hi, Mom";
        close(fd1[0]);
        close(fd2[1]);
        
        char* chrec = malloc(10);
        write(fd1[1], msg, strlen(msg));
        //printf("Wrote to parent %s\n", msg);
        read(fd2[0], chrec, 10);
        printf("My mom said %s\n", chrec);

        close(fd1[1]);
        close(fd2[0]);
    }else{
        char* msg2 = "I love you";
        close(fd1[1]);
        close(fd2[0]);

        char* prec = malloc(7);

        read(fd1[0], prec, 7);
        printf("My child said %s\n", prec);
        write(fd2[1], msg2, strlen(msg2));

        close(fd1[0]);
        close(fd2[1]);
        wait(NULL);
    }
    return 0;
}
