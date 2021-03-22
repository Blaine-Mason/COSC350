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
    char buf;
    
    inFile = open(argv[1], O_RDONLY);
    if(inFile < 0){
        puts("Input File Error");
        exit(1);
    }
    int len = lseek(inFile, 0, SEEK_END);
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
            for (int i = 0; i < len; i++){
                lseek(inFile, i, SEEK_SET);
                read(inFile, &buf,1);
                if(!isDigit(buf)){
                    write(childOut, &buf, 1);
                }
            }
            puts("Child Done!");
            break;
        default:
            parentOut = open("parentOutput.txt", O_RDWR | O_CREAT, 0666);
            if(parentOut < 0){
                puts("ERROR OPENING FILE");
                exit(1);
            }
            for(int j = 0; j < len; j++){
                lseek(inFile, j, SEEK_SET);
                read(inFile, &buf, 1);
                if(isDigit(buf)){
                    write(parentOut, &buf, 1);
                }
            }
            puts("Parent Done!");
            break;
    }
    close(inFile);
    close(parentOut);
    close(childOut);
    exit(0);

}
