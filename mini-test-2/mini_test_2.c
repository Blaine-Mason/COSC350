#include <stdio.h>
#include <stdlib.h>


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
        puts("Must call ./sum with a number as an argument!");
        exit(-1);
    }

    int num_numbers = argc-1;
    int nums[num_numbers];
    for(int i = 0; i < num_numbers; i++){
        nums[i] = new_atoi(argv[i+1]);
    }

    int sum_even = 0, sum_odd = 0;
    for(int j = 0; j < num_numbers; j++){
        if(nums[j] % 2 == 0){
            sum_even += nums[j];
        }else{
            sum_odd += nums[j];
        }
    }
    printf("The sum of even numbers is %d\n", sum_even);
    printf("The sum of odd numbers is %d\n", sum_odd);

    return 0;
}