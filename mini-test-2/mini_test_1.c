#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    int inFile, outFile, bytes;
    char buf;
    inFile = open("foo", O_RDONLY);
    outFile = open("symmetry", O_RDWR | O_CREAT | O_EXCL, 0600);

   
    int offset = lseek (inFile, 0, SEEK_END);
    if(offset == -1){
        printf("Cannot seek input file foo");
        exit(1);
    }
    int i;
    for(i = 0; i <= offset; i++){
        if((lseek(inFile, -i, SEEK_END)) == -1){
            puts("Create lseek Error");
        }
        read(inFile, &buf, 1);
        write(outFile, &buf, 1);
    }
    write(outFile, " || ", 4);
    lseek (inFile, 0, SEEK_SET);
    while(read(inFile, &buf, 1) == 1){
        write(outFile, &buf, 1);
    }
    write(outFile, "\n", 1);
    close(inFile);
    close(outFile);
    return 0;
}