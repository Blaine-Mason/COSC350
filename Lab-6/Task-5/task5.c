#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

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
    parentOut = open("parentOutput.txt", O_RDWR | O_CREAT, 0666);
    childOut = open("childOutput.txt", O_RDWR | O_CREAT, 0666);
    if(parentOut < 0 || childOut < 0){
        puts("OUT FILE ERROR");
        exit(1);
    }
    
    pid = fork();
    switch(pid){
        case -1:
            puts("ERROR FORKING");
            exit(1);
        case 0:
            while(read(inFile, &buf, 1)){
                printf("Child Buffer: %s\n", &buf);
                if(!isDigit((int)buf)){
                    write(childOut, &buf, 1);
                } 
            }
            puts("Child Done!");
            break;
        default:
            while(read(inFile, &buf, 1)){
                printf("Parent Buffer: %s\n", &buf);
                if(isDigit((int)buf)){
                    write(parentOut, &buf, 1);
                }
            }
            break;
    }
    close(inFile);
    close(parentOut);
    close(childOut);
    exit(0);

}
