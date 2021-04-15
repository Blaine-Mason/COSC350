#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(){
    pid_t pid;
    int fdes[2];
    int number1, number2, number3;
    pipe(fdes);
    pid = fork();
    if(pid == -1){
        puts("ERROR FORKING");
        return 1;
    }
    if(pid == 0){
        close(fdes[0]);
        printf("Enter two numbers: ");
        scanf("%d%d", &number1, &number2);
        number1 *= number2;
        write(fdes[1], &number1, sizeof(int));
        close(fdes[1]);
    }else{
        close(fdes[1]);
        read(fdes[0], &number3, sizeof(int));
        printf("I recieved %d from the child\n", number3);
        close(fdes[1]);
    }
    return 0;
}
