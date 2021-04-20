#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void handler(int sig){
	if(sig==SIGUSR1){
		printf("i is 10 and now i kill everyone.\n");
        _exit(0);
    }
}

void *firstThread(void* arg){
    int i = 0;
    while(1){
        printf("iter = %d\n", i);
        i++;
        sleep(1);
        if(i == 10){
            //kills all threads includeing original 
            exit(0);
        }
    }
}

void *secondThread(void* arg){
    while(1){
        puts("I am thread two and I am still running");
        sleep(1);
    }
}
int main(){
    pthread_t thread1;
    pthread_t thread2;
    pthread_t thread3;
    thread3 = pthread_self();
    pthread_create(&thread1, NULL, firstThread, NULL);
    pthread_create(&thread2, NULL, secondThread, NULL);

    while (1)
    {
        printf("I am original thread and I am still running\n");
        sleep(1);
    }
    
    return 0;


}