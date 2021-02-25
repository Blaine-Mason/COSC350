/* copyStdIO.c copy standard input to standard output */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /*STDIN_FILENO, STDOUT_FILENO*/
/* buffer size effect the efficiency of the program */
#define BUFFER_SIZE 2
void err_sys(char *str)
{
    printf ("%s",str);
    exit (1);
}
int main(){
    int nbyte;
    char buffer[BUFFER_SIZE];
    while ((nbyte = read(STDIN_FILENO, buffer, BUFFER_SIZE)) >0)
        if (write (STDOUT_FILENO, buffer, nbyte) != nbyte)
            err_sys ("Write Error");
        if (nbyte <0)
            err_sys("read Error");
    exit (0);
}
