// Rewrite Task#5 by using pread() system call instead of using lseek() system call.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
    int inFile, outFile; 
    int byteCount = -1;
    char buf;
    inFile = open("foo", O_RDONLY);
    umask(0);
    outFile = open("foorev1", O_RDWR | O_CREAT | O_EXCL, 0760);
    while(read(inFile, &buf, 1)){
        byteCount++;
    }
    while(byteCount > 0){
        pread(inFile, &buf, 1, byteCount - 1);
        write(outFile, &buf, 1);
        byteCount--;
    }

    close(inFile);
    close(outFile);
    exit(0);
}