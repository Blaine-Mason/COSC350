#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc > 3 ){
        puts("Too many parameters given!");
        exit(1);
    }

    int inFile, outFile, asc;
    char buf;

    inFile = open(argv[1], O_RDONLY);

}
