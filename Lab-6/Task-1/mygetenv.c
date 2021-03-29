#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSTRINGSZ 4096

static char envbuf[MAXSTRINGSZ];

extern char **environ;

char* mygetenv(const char* name){
    int i, len;
    len = strlen(name);
    for(i = 0; environ[i] != NULL; i++){
        if((strncmp(name, environ[i], len) == 0) && (environ[i][len] == '=')){
            strncpy(envbuf, &environ[i][len+1], MAXSTRINGSZ);
            return(envbuf);
        }
    }
    return(NULL);
}

int main(){
    printf("PATH : %s\n", mygetenv("PATH"));
    printf("HOME : %s\n", mygetenv("HOME"));
    printf("USER : %s\n", mygetenv("USER"));
    return 0;
}
