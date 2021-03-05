#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
    if(argc != 6){
        printf("Only %d parameters passed in, 5 required!", argc - 1);
        exit(1);
    }

    int inFile, alphaFile, numFile, otherFile, copy;
    char buf;

    inFile = open(argv[1], O_RDONLY);
    alphaFile = open(argv[2], O_RDWR | O_CREAT, 0666);
    numFile = open(argv[3], O_RDWR | O_CREAT, 0666);
    otherFile = open(argv[4], O_RDWR | O_CREAT, 0666);
    copy = open(argv[5], O_RDWR | O_CREAT, 0666);

    int sizeOfFile = lseek(inFile, 0, SEEK_END); // Get size of file
    lseek(inFile, 0, SEEK_SET);
    printf("Size of file: %d\n", sizeOfFile);
    
    int spc = 32;
    int newLine = 10;
    while(read(inFile, &buf, 1)){
        if(((int)buf >= 65 && (int)buf <= 90) || ((int)buf >= 97 && (int)buf <= 122)){
            write(alphaFile, &buf, 1);
            write(numFile, &spc, 1);
            write(otherFile, &spc, 1);
        }
        else if(((int)buf >= 48 && (int)buf <= 57)){
            write(numFile, &buf, 1);
            write(alphaFile, &spc, 1);
            write(otherFile, &spc, 1);    
        }
        else if((int)buf == 10){
            write(numFile, &newLine, 1);
            write(alphaFile, &newLine, 1);
            write(otherFile, &newLine, 1);      
        }
        else{
            write(otherFile, &buf, 1);
            write(numFile, &spc, 1);
            write(alphaFile, &spc, 1);
        }
    }
    lseek(alphaFile, 0, SEEK_SET);
    lseek(numFile, 0, SEEK_SET);
    lseek(otherFile, 0, SEEK_SET);
    char aBuff, nBuff, oBuff;
    for(int i = 0; i < sizeOfFile; i++){
        read(alphaFile, &aBuff, 1);
        read(numFile, &nBuff, 1);
        read(otherFile, &oBuff, 1);
        if(aBuff == nBuff ==  oBuff){
            write(copy, &aBuff, 1);
        }else if ((aBuff == nBuff) && (aBuff == ' ')){
            write(copy, &oBuff, 1);            
        }else if ((aBuff == oBuff) && (aBuff == ' ')){
            write(copy, &nBuff, 1);             
        }else{
            write(copy, &aBuff, 1);
        }
    }
    return 0;
}