// Write a simple c code which open a file (foo) as a input and write into a file by using the lseek
// system call (foorev)as a reverse order (created output file mode will be rwxrw---).

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>


int main(){
    int inFile, outFile, bytes;
    char buf;
    inFile = open("foo", O_RDONLY);
    umask(0);
    outFile = open("foorev", O_RDWR | O_CREAT | O_EXCL, 0760);

    while(read(inFile, &buf, 1) == 1){
        write(outFile, &buf, 1);
    }
    int offset = lseek(inFile, 0, SEEK_END);

    if(offset == -1){
        printf("Cannot seek input file foo");
        exit(1);
    }
    int i;
    for(i = 1; i <= offset; i++){
        if((lseek(inFile, -i, SEEK_END)) == -1){
            puts("Error While Seeking");
        }
        read(inFile, &buf, 1);
        int wri = write(outFile, &buf, 1);

    }
    close(inFile);
    close(outFile);
    return 0;
}