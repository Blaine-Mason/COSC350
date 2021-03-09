#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>


int palind(int fd1, int fd2){
    char buf1, buf2;
    int offset = lseek(fd1, 0, SEEK_SET);
    int offset2 = lseek(fd2, 0, SEEK_END);
    int i;
    for(i = 2; i <= offset2; i++){
        if((lseek(fd2, -i, SEEK_END)) == -1){
            puts("Error While Seeking");
        }
        read(fd1, &buf1, 1);
        read(fd2, &buf2, 1);
        if(buf1 != buf2){
            return 0;
        }
    }
    return 1;
}


int main(int argc, char* argv[]){
    int fd1 = open(argv[1], O_RDONLY);
    int fd2 = open(argv[1], O_RDONLY);
    int isPalind = palind(fd1, fd2);
    printf("%d", isPalind);
    return 0;
}
