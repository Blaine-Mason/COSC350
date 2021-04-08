#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

void readScores(int *scores){
    int score;
    int numScores = 0;
    for (int i = 0; i < 20 && scores[i] != -1; i++){
        printf("Enter positive test score %d (-1 to stop): ", i+1);
        scanf("%d", &score);
        if(score < -1){
            puts("This is easy program, no invalid scores, go enter them again");
            pthread_exit(NULL);
        }
        scores[i] = score;
        numScores++;
    }
    for(int j = 0; j < numScores - 1; j++){
        int min = j;
        for(int n = j + 1; n < numScores; n++){
            if (scores[n] < scores[min]){
                min = n;
            }
        }
        int temp = scores[j];
        scores[j] = scores[min];
        scores[min] = temp;
    }
    pthread_exit(NULL);
}

void avgMedian(int* scores){
    double avg, med;
    int total, i;
    for(i = 0; scores[i] != -1; i++){
        total += scores[i];
    }
    avg = (double)total/i;

    if(i % 2 == 0){
        int right = (i/2)-1;
        int left = (i/2);
        med = (double)(scores[right] + scores[left])/2;
    }else{
        med = scores[i/2];
    }
    printf("Average score: %2.2f  Median score: %2.2f\n", avg, med);
    pthread_exit(NULL);
}

void minMax(int* scores){
    int i;
    int min, max;

    min = scores[0];
    for(int i = 0; scores[i] != -1; i++){
        max = scores[i];
    }
    printf("Min Score: %d  Max Score: %d\n", min, max);
    pthread_exit(NULL);
}

void clearBuff(int* scores){
    int i;

    for(i = 0; i < 20; i++){
        scores[i] = 0;
        printf("%d ", scores[i]);
    }
    puts("");
    puts("Buffer CLeared");
    pthread_exit(NULL);
}

int main(int argc, char* argv[]){
    pthread_t threads[4];
    int rc, i;

    int* scores = malloc(20*sizeof(int));
    rc = pthread_create(&threads[0], NULL, readScores, (void*)scores);
    if(rc){
        printf("ERROR THREAD 1\n");
        exit(-1);
    }
    pthread_join(threads[0], NULL);
    
    rc = pthread_create(&threads[1], NULL, avgMedian, (void *)scores);
    if(rc){
        printf("ERROR THREAD 2\n");
        exit(-1);
    }
    rc = pthread_create(&threads[2], NULL, minMax, (void *)scores);

    if(rc){
        printf("ERROR THREAD 3\n");
        exit(-1);
    }
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL);
    
    rc = pthread_create(&threads[3], NULL, clearBuff, (void *)scores);
    if(rc){
        printf("ERROR THREAD 4\n");
        exit(-1);
    }
    pthread_join(threads[3], NULL);
    pthread_exit(NULL);
    return 0;





}
