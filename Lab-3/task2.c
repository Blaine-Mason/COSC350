#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
    int inFile, outFile;
    char Ach;
    inFile = open("foo", O_RDONLY);
    outFile = open("clone1", O_RDWR | O_CREAT | O_EXCL, 0666);

    while(read(inFile, &Ach, 1) == 1){
        write(outFile, &Ach, 1);
    }

    close(inFile);
    close(outFile);
    return 0;
}