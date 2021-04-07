#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void* firstThread(){
    while (1)
    {
        printf("This is the first thread\n");
        pthread_testcancel();
        sleep(1);

    }
    printf("The first thread job is done\n");
    pthread_exit(NULL);
}

void* secondThread(void* pthread1){
    pthread_t id = (pthread_t)pthread1;
    for(int i = 0; i < 10; i++){
        printf("This is the second thread\n");
        sleep(1);
    }
    pthread_cancel(id);
    printf("The second thread job is done\n");
    return NULL;
}


int main(){
    pthread_t thread1;
    pthread_t thread2;

    int t1, t2;
    t1 = pthread_create(&thread1, NULL, firstThread, NULL);
    t2 = pthread_create(&thread2, NULL, secondThread, &thread1);
    while (1)
    {
        printf("I am original thread\n");
        sleep(1);
    }

    return 0;


}