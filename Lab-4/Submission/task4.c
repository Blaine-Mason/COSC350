#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>


int main(){
    mkdir("/Users/blaine-mason/Dir1", 0777);
    mkdir("/Users/blaine-mason/Dir2", 0777);
    mkdir("/Users/blaine-mason/Dir2/Dir21", 0777);
    
    int inFile, outFile;
    char buf;
    
    inFile = open("/Users/blaine-mason/hello", O_RDONLY);
    outFile = open("/Users/blaine-mason/Dir2/Dir21/hello", 
                   O_RDWR | O_CREAT, 0766);
    
    while(read(inFile, &buf, 1)){
        write(outFile, &buf, 1);
    }
    close(inFile);
    close(outFile);
    symlink("/Users/blaine-mason/Dir2/dir21/", "/Users/blaine-mason/Dir1/toDir21");
    symlink("/Users/blaine-mason/Dir2/Dir21/hello", "/Users/blaine-mason/Dir1/toHello");    
    return 0;    

}
