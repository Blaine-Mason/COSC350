#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* calculatesum(void* n){
    int i;
    int sum = (int)n;
    for(i = sum - 1; i > 0; i--){
        sum += i;
    }
    return (void *)sum;
}

void* factorial(void* n){
    int i;
    int total = (int)n;
    for(i = total - 1; i > 0; i--){
        total *= i;
    }
    return (void *)total;
}

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
    pthread_t sumThread, factorialThread;
    int rc;

    int num = new_atoi(argv[1]);
    rc = pthread_create(&sumThread, NULL, calculatesum, (void *)num);
    if(rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    
    rc = pthread_create(&factorialThread, NULL, factorial, (void *)num);
    if(rc){
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    void* sum; 
    void* fact;
    pthread_join(sumThread, &sum);
    pthread_join(factorialThread, &fact);
    printf("Sum: %d\n", (int)sum);
    printf("Factorial: %d\n", (int)fact);

    pthread_exit(NULL);
    return 0;
}
