#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void *firstThread(void* arg){
    int number = (int)arg;
    number += 10;
    printf("First thread computed: %d\n", number);
    return ((void*)number);
}

void *secondThread(void* arg){
    int number = (int)arg;
    number += 20;
    printf("Second thread computed: %d\n", number);
    return ((void*)number);
}

void *thirdThread(void* arg){
    int number = (int)arg;
    number += 30;
    printf("Third thread computed: %d\n", number);
    return ((void*)number);
}

int new_atoi(char* str){
    int ret = 0, i = 0, neg = 0;
    for(; str[i] != '\0'; ++i){
        ret = ret * 10 + (str[i] - '0');
    }
    return ret;
}

int main(int argc, char* argv[]){
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    int num = new_atoi(argv[1]);
    printf("Number: %d\n", num);
    void* t1Value;
    void* t2Value;
    void* t3Value;
    pthread_create(&thread1, NULL, firstThread, (void*)num);
    pthread_join(thread1, &t1Value);

    pthread_create(&thread2, NULL, secondThread, (void*)t1Value);
    pthread_join(thread2, &t2Value);

    pthread_create(&thread3, NULL, thirdThread, (void*)t2Value);
    pthread_join(thread3, &t3Value);

    printf("The three thread’s calculation result is %d\n", (int)t3Value);

    return 0;


}