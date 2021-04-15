#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include<pthread.h>

#define MAXLINE 256

int main(int argc, char* argv[]){
    //Same as in slides, but just modified.
    int n1, n2;
    char buffer[BUFSIZ];
    char notnumber;
    FILE* ptr;
    char readLine[MAXLINE];
    //popen gets our two numbers.
    ptr = popen("./any", "r");
    while (fgets(buffer, BUFSIZ, ptr)){
        //checks for 2 ints
        //Having %d%d%s eliminates the case where 2 2g could get passed.
        // (int)(int)(char) == 2 only accepts two ints because the (char) picks up any occurance of a char in the input.
        if(sscanf(buffer, "%d%d%s", &n1, &n2, &notnumber) == 2){
            //prints the product
            printf("The product is %d\n", n1*n2);
        }else{
            //if 34 f is entered this will display
            write(STDOUT_FILENO, "Invalid input! You must enter two integers.\n", 45);
        }
        sleep(1);
    }
    return 0;
} 