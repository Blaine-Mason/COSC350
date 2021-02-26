#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
    int inFile, outFile, bytes;
    char buf[32];
    inFile = open("foo", O_RDONLY);
    outFile = open("clone2", O_RDWR | O_CREAT | O_EXCL, 0770);

    while((bytes = read(inFile, &buf, 32)) > 0){
        write(outFile, &buf, bytes);
    }

    close(inFile);
    close(outFile);
    return 0;
}