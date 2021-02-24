#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

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
int sum(int n){
    int sum = 0, rem = 0;
    while(n != 0){
        rem = n % 10;
        sum += rem;
        n = n/10;
    }
    return sum;
}

int main(int argc, char *argv[]){
    if(argc == 1){
        puts("Must call ./task7 with a number as an argument!");
        exit(-1);
    }
    int number = new_atoi(argv[1]);
    printf("Sum: %d\n", sum(number));
    return 0;
}