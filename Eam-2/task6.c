#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS 2
pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *thread1(){
    while(1){
        if(counter < 10){
            pthread_mutex_lock(&count_mutex);
            counter++;
            printf("Hi!, thread #%d! shared variable count = %d\n", 1, counter);
            pthread_mutex_unlock(&count_mutex);
        }
    }
}
void *thread2(){
    while(1){
        if(counter > 0){
            pthread_mutex_lock(&count_mutex);
            counter--;
            printf("Hi!, thread #%d! shared variable count = %d\n", 2, counter);
            pthread_mutex_unlock(&count_mutex);
        }
    }
}
int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    pthread_create(&threads[0], NULL, thread1, NULL);
    pthread_create(&threads[1], NULL, thread2, NULL);
    
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}