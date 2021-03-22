#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

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
    if(argc != 2){
        puts("ERROR");
        exit(1);
    }
    int n = new_atoi(argv[1]);
    char word[n];
    int i;
    for(i = 0; i < n; i++){
        word[i] = rand()%26 + 'a';
    }
    printf("Your random %d characters are: %s\n", n, word);
}