#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<pthread.h>

#define MAXLINE 256

int main(int argc, char* argv[]){
    int len, size, num1, num2;
    int fileDes[2];
    pid_t pid;
    char setLine[MAXLINE], readLine[MAXLINE];
    
    pipe(fileDes);
    pid = fork();
    if(pid > 0){
        close(fileDes[0]);
        printf("Enter 2 integers");
        while ((size = read(STDIN_FILENO, setLine, MAXLINE)) > 0){
            write(fileDes[1], setLine, size);
            sleep(1);
            printf("Enter 2 integers");
        }
            
    }else{
        close(fileDes[1]);
        while((len = read(fileDes[0], readLine, MAXLINE)) > 0){
            if(sscanf(readLine, "%d%d", &num1, &num2) == 2){
                sprintf(readLine, "The sum is %d\n", num1+num2);
                len = strlen(readLine);
                write(STDOUT_FILENO, readLine, len);
            }else{
                write(STDOUT_FILENO, "Invalid input! You must enter two integers.\n", 45);
            }
        }
    }
 return 0;
} 
