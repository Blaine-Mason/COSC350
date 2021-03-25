#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

int isDigit(int c){
    return (c >= 48 && c <=57);
}
int main(int argc, char *argv[]){
    pid_t pid;
    int inFile, childOut, parentOut;
    int pOffset = 0;
    int cOffset = 0;
    char buf;
    
    inFile = open(argv[1], O_RDONLY);
    if(inFile < 0){
        puts("Input File Error");
        exit(1);
    }
    umask(0); 
    pid = fork();
    switch(pid){
        case -1:
            puts("ERROR FORKING");
            exit(1);
        case 0:
            childOut = open("childOutput.txt", O_RDWR | O_CREAT, 0666);
            if(childOut < 0){
                puts("ERROR OPENING FILE");
                exit(1);
            }
            while(pread(inFile, &buf,1, pOffset)){
                if(!isDigit(buf)){
                    write(childOut, &buf, 1);
                }
                pOffset++;
            }
            puts("Child Done!");
            break;
        default:
            parentOut = open("parentOutput.txt", O_RDWR | O_CREAT, 0666);
            if(parentOut < 0){
                puts("ERROR OPENING FILE");
                exit(1);
            }
            while(pread(inFile, &buf, 1, cOffset)){
                if(isDigit(buf)){
                    write(parentOut, &buf, 1);
                }
                cOffset++;
            }
            puts("Parent Done!");
            break;
    }
    close(inFile);
    close(parentOut);
    close(childOut);
    
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
    exit(0);

}
