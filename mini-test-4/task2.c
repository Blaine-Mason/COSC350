#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
void cleanup(void* arg){
    pthread_t tid = (pthread_t) arg;
    int rc;
    printf("The first thread job is done! \n");
    rc = pthread_cancel(tid);
}
void Bye1(void* arg){
    printf("Original thread job is done. \n");
}
void *firstThread(void* arg){
    pthread_t id = (pthread_t)arg;
    pthread_cleanup_push(cleanup, (void*)id);
    while (1)
    {
        printf("This is the first thread\n");
        pthread_testcancel();
        sleep(1);
    }
    pthread_cleanup_pop(0);
}

void *secondThread(void* pthread1){
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
    pthread_t thread3;
    thread3 = pthread_self();
    int t1, t2;
    pthread_cleanup_push(Bye1, NULL);
    t1 = pthread_create(&thread2, NULL, firstThread, (void*)thread3);
    t2 = pthread_create(&thread1, NULL, secondThread, (void*)thread2);
    while (1)
    {
        printf("I am original thread\n");
        pthread_testcancel();
        sleep(1);
    }
    pthread_cleanup_pop(0);
    
    return 0;


}
