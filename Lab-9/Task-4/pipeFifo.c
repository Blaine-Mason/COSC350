#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

#define name "/tmp/task4_fifo"

// After swapping read and write:
// Wrote -1 bytes.
// Read -1 bytes:
const int READ_END = 0;
const int WRITE_END = 1;

int main(int argc, char* argv[])
{
    int fifo, fd;
    int data_processed;
    const char some_data[] = "123";
    char* buffer = malloc(3 * sizeof(char));
    memset(buffer, '\0', 3);
    
    fifo = mkfifo(name, 0777);
    fd = open(name, O_RDWR);
    data_processed = write(fd, some_data, strlen(some_data));
    printf("Wrote %d bytes. \n", data_processed);
    data_processed = read(fd, buffer, 3);
    printf("Read %d bytes: %s \n", data_processed, buffer);

    free(buffer);
    exit(EXIT_SUCCESS);
}
