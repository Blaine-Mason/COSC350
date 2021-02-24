#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    int inFile, bytes, count = 0;
    char buf;
    inFile = open(argv[1], O_RDONLY);
    while((bytes = read(inFile, &buf, 1)) > 0){
        count++;
    }
    printf("Size of file is %d Bytes\n", count);

    close(inFile);
}