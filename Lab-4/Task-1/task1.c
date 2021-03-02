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

    int inFile, outFile, asc, temp;
    char buf;
    
    inFile = open(argv[1], O_RDONLY);   
    umask(0);
    outFile = open(argv[2], O_RDWR | O_CREAT, 0666);
    
    if(inFile && outFile){
        dup2(outFile, 1);
        while((temp = read(inFile, &asc, 1)) > 0){
            if(asc == 10){
                printf("\n");
            }else if(asc == 32){
                buf = asc;
                printf("  ");
            }else if(asc != 32){
                printf("%c ", buf);
            }
        }
    }
}
