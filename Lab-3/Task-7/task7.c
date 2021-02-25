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

int main(int argc, char *argv[]){
    if(argc == 1){
        puts("Must call ./task7 with a number as an argument!");
        exit(-1);
    }
    int num_numbers = argc-1;
    int nums[num_numbers];
    for(int i = 0; i < num_numbers; i++){
        nums[i] = new_atoi(argv[i+1]);
    }

    int sum = 0;
    for(int j = 0; j < num_numbers; j++){
        sum += nums[j];
    }
    printf("The sum of the arguments is: %d\n", sum);
}