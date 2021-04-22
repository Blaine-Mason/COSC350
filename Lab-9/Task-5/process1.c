//sender.c
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/shm.h>
#include<errno.h>
#include "header.h"
int main(int argc, char *argv[])
{
    int shmid;
    key_t key;
    struct Memory *shm;
    int n, n1, n2, i;
    key = ftok(".", 'x'); //get key value
    if ((shmid = shmget(key, sizeof(struct Memory), 0)) <0) //open shared memory
    {
        perror("shmget error \n");
        exit (1);
    }
    shm = (struct Memory *) shmat(shmid, NULL, 0); //attach to shared memory
    if ((long)shm == -1)
    {
        perror("shmat error \n");
        exit (1);
    }
    shm->gostop = GO;
    shm->status = NOT_READY;
    char* input = calloc(100,sizeof(int));
    while(fgets(input,100,stdin)){
        printf("Enter two integers: \n");
        if(sscanf(input, "%d%d", &n1, &n2) == 2){
            shm->num1 = n1;
            shm->num2 = n2;
            shm->status = FILLED;
            while (shm->status != TAKEN)
            ;

            printf("Data is taken by other process\n");
        }else{
            printf("Invalid input! You must enter two integers.\n");
        }
        
    }
    shm->gostop = STOP;
    shmdt((void *) shm); //detach
return 0;
}