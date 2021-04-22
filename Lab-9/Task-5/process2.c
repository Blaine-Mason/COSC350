//receiver.c
#include<stdio.h>
#include<stdlib.h>
#include<sys/shm.h>
#include<errno.h>
#include "header.h"
int main(int argc, char *argv[])
{
    int shmid, n, int1, int2;
    key_t key;
    struct Memory *shm;
    key = ftok(".", 'x');//get key value
    // open existing shared memory

    if ((shmid = shmget(key, sizeof(struct Memory), 0)) <0)
    {
    perror("shmget error \n");
    exit (1);
    }

    //a pointer is attach to shared memory

    shm = (struct Memory *) shmat(shmid, NULL, 0);
    if ((long)shm == -1)
    {
        perror("shmat error \n");
        exit (1);
    }
    // read from the shared memory
    while (shm->gostop == GO)
    {
        while (shm->status != FILLED)
        {
            if (shm->gostop == STOP)
                break;
            ;
        }
        printf ("Number 1: %d \n", shm->num1);
        printf ("Number 2: %d\n", shm->num2);
        printf ("Sum: %d\n", shm->num1 + shm->num2);
        shm->status = TAKEN;
    }
    shmdt((void *) shm); //detach
    return 0;
}