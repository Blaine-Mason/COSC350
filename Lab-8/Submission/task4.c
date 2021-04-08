#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char* argv[]){
    int i, size = 0;
    char* command;

    for(i = 1; i < argc; i++){
        size += strlen(argv[i]);
    }
    command = calloc(size, sizeof(char));
    for(i = 1; i < argc; i++){
        sprintf(command, "%s %s", command, argv[i]);
    }

    char buf[BUFSIZ];
    FILE *fileptr;
    if (fileptr = popen(command, "r")){
        while(fgets(buf, BUFSIZ, fileptr)){
            (void)printf("%s", buf);
        }
    }

    pclose(fileptr);

    return 0;
}