//anyinput.c
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define MAXLINE 256
int main()
{
    char rline[MAXLINE];
    int size;
    
    while ( (size = read(STDIN_FILENO, rline, MAXLINE)) > 0)
    {
        write(STDOUT_FILENO, rline, size); /*write to a pipe */
    }
 return 0;
} 