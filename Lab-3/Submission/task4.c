// Write a simple c code which open two files (foo, foo1)and append to a file (foo12) by using the
// lseek system call (created output file mode will be rwxrw---).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
    int inFile, inFile2, outFile, bytes;
    char buf;
    inFile = open("foo", O_RDONLY);
    inFile2 = open("foo1", O_RDONLY);
    outFile = open("foo12", O_RDWR | O_CREAT | O_EXCL, 0760);

    while(read(inFile, &buf, 1) == 1){
        write(outFile, &buf, 1);
    }
    int offset;
    if ((offset = lseek(outFile, 0, SEEK_END)) == -1)
        printf("cannot seek.\n");
    else{
        while(read(inFile2, &buf, 1) == 1){
            write(outFile, &buf, 1);
        }    
    }
    close(inFile);
    close(inFile2);
    close(outFile);
    return 0;
}