// Justin Ventura COSC350

// Included libraries:
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>

// From book:
#include <sys/types.h>
#include <signal.h>

// Define useful constants:
#define BUFFER_SIZE 1

// Error logging.
void err_sys(char *str);

// Signal Handler:
void sig_handler(int sig);

int main(int argc, char **argv) {

    // Check for arguments.

    // Initialize the signal handeler.
    signal(SIGUSR1, sig_handler);
    signal(SIGUSR2, sig_handler);

    // Begin forking:
    pid_t id1 = fork();
    pid_t id2;
    if (id1 != 0) {

        id2 = fork();

    }
    /**
     * Parent id1 = C1_ID, parent id2 = C2_ID.
     * 
     * C1 id1 = 0, CHILD1 id2 = NONE.
     * 
     * C2 id1 = CHILD1, CHILD2 id2 = 0.
     * 
     */
    switch(id1) {

        case -1:

            err_sys("Forking Error.");

        // CHILD 1
        case 0:

            kill(getppid(), SIGUSR1);
            break;
        
        default:

            // CHILD 2
            if (id2 == 0) {

                kill(getppid(), SIGUSR2);
                break;

            } 
            // PARENT
            else {

                wait(NULL);
                wait(NULL);
                
            }

    }

    exit(EXIT_SUCCESS);
}

// Error logging.
void err_sys(char *str) {
    printf("%s\n",str);
    exit(EXIT_FAILURE);
}

// Signal handler.
void sig_handler(int sig) {

    if(sig == SIGUSR1) {

        printf("Hi Honey! Anything wrong?\n");

    }
    else if(sig == SIGUSR2) {

         printf("Do you make trouble again?\n");

    }
       
}
