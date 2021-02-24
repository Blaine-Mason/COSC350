#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc > 3){
        puts("Too many parameters given!");
        exit(1);
    }

    int inFile, outFile, asc;
    char buf;

    inFile = open(argv[1], O_RDONLY);
    umask(0);
    outFile = open(argv[2], O_RDWR | O_CREAT, 0666);

    if(inFile && outFile){
        dup2(outFile, 1);
        while((asc = read(inFile, &buf, 1)) > 0){
            if(buf != ' '){
                printf("%d", asc);
            }else if(buf == ' '){
                printf("%d ", (int)buf);
            }else if((int)buf == 10){
                printf("\n");
            }
        }
    }else{
        puts("Error opening in/out file");
    }

    close(inFile);
    close(outFile);
    exit(0);
}