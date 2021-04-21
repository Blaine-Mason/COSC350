#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include<pthread.h>
#include<sys/wait.h>

int main()
{
    int data_processed, data_write;
    int file_pipes[2];
    int fd2[2]; //p -> c
    //[0] -> READ
    //[1] -> WRITE
    const char msg[] = "Hi there, kiddo";
    char buffer[BUFSIZ + 1];
    pid_t fork_result;

    memset(buffer, '\0', sizeof(buffer));
    if (pipe(file_pipes) == 0 && pipe(fd2) == 0) {
        fork_result = fork();
        if (fork_result == (pid_t)-1) {
            fprintf(stderr, "Fork failure");
            exit(EXIT_FAILURE);
        }if (fork_result == 0) {
            char rBuffer[BUFSIZ + 1];
            char wBuffer[BUFSIZ + 1];
            close(file_pipes[1]);
            close(fd2[0]);
            sprintf(rBuffer, "%d", file_pipes[0]);
            sprintf(wBuffer, "%d", fd2[1]);
            (void)execl("twoPipesChild", "twoPipesChild", rBuffer, wBuffer, (char *)0);
            close(file_pipes[0]);
            close(fd2[1]);
            exit(EXIT_FAILURE);
        }else {
            close(file_pipes[0]);
            close(fd2[1]);
            data_processed = write(file_pipes[1], msg, strlen(msg));
            data_write = read(fd2[0], buffer, 6);
            printf("Process %d(parent) wrote %d bytes to the child. \n", getpid(), (int)strlen(msg));
            wait(&fork_result);
            printf("Process %d(parent) recieved the message \" %s \" made of %d bytes. \n", getpid(), buffer, data_write);
            close(file_pipes[1]);
            close(fd2[0]);
        }
    }
    exit(EXIT_SUCCESS);
}