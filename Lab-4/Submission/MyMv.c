#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
//Dr.Park is a nice guy
int main(int argc, char* argv[]){

    int len1 = strlen(argv[1]);
    int len2 = strlen(argv[2]);
    struct stat buf;
    stat(argv[2], &buf);
    char finalPath[len1 + len2];
    if(S_ISDIR(buf.st_mode)){
        sprintf(finalPath, "%s", argv[2]);
        sprintf(finalPath, "%s/%s", finalPath, argv[1]);
        link(argv[1], finalPath);
        unlink(argv[1]);
    }else{
        puts("The directory does not exists, creating it.\n");
        sprintf(finalPath, "%s", argv[2]);
        sprintf(finalPath, "%s/%s", finalPath, argv[1]);
        printf("The file: %s is now located at: %s", argv[1], finalPath);
        mkdir(argv[2], 0777);
        link(argv[1], finalPath);
        unlink(argv[1]);
    }
    return 0;
}
