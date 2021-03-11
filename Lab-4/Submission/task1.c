#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int new_atoi(char* str){
    int ret = 0, i = 0, neg = 0;
    if(str[0] == '-'){
        neg = 1;
        i++;
    }
    for(; str[i] != '\0'; ++i){
        ret = ret * 10 + (str[i] - '0');
    }
    if(neg){
        return ret*(-1);
    }else{
        return ret;
    }
}


int main(int argc, char* argv[]){
    if(argc > 3 ){
        puts("Too many parameters given!");
        exit(1);
    }

    int inFile, outFile, asc;
    char buf[1], buff[4];
    int i = 0;
    
    
    inFile = open(argv[1], O_RDONLY);   
    umask(0);
    outFile = open(argv[2], O_RDWR | O_CREAT, 0666);
    
    if(inFile && outFile){
        while(read(inFile, &buf, 1) > 0){
            if(buf[0] == ' '){
                buff[i] = '\0';
                int ascii = new_atoi(buff);
                char toWrite = ascii;
                write(outFile, &toWrite, 1);
                i = 0;
            }else if(buf[0] == '\n'){
                write(outFile, "\n", 1);
            }else{
                buff[i] = buf[0];
                i++;
            }
        }
    }
    return 0;
}
