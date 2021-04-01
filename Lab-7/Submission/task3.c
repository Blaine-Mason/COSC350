#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    int fd_parent, fd_child;
    char buf;
    char str[] = "Hi Mom";

    pid = fork();
    switch(pid){
        case -1:
            puts("Fork Failed");
            return -1;
        case 0:
            fd_child = open("foo", O_WRONLY|O_CREAT|O_EXCL, 0600); 
            write(fd_child, &str, 6);
            break;
        default:
            wait(&pid);
            fd_parent = open("foo", O_RDONLY);
            printf("My son said ");
            while(read(fd_parent, &buf, 1)){
                printf("%c", buf);
            }
            puts("");
            break;
    }
    close(fd_parent);
    close(fd_child);

}
