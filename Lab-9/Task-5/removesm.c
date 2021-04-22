// removesm.c
#include<stdio.h>
#include<sys/shm.h>
#include<errno.h>
#include<stdlib.h>
#include "header.h"
int main(int argc, char *argv[]) {
    key_t key;
    int shmid;
    struct Memory shm;
    key = ftok(".", 'x');
    if ((shmid = shmget(key, sizeof(struct Memory), 0)) <0)
    {
        perror("shmget error \n");
        exit (1);
    }
    shmctl(shmid, IPC_RMID, NULL);
    return 0;
}