#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char** argv){
	int data_processed, data_to_send;
	char buffer[BUFSIZ+1];
	int writeF, readF;
    char msg[] = "Hi Mom";
	memset(buffer,'\0',sizeof(buffer));
	sscanf(argv[1],"%d",&readF);
    sscanf(argv[2],"%d",&writeF);
	data_processed=read(readF,buffer,BUFSIZ);
	data_to_send=write(writeF, msg, 6);
    
    printf("Process %d(child) recieved the message \" %s \" made of %d bytes. \n", getpid(), buffer, data_processed);
    printf("Process %d(child) sent %d bytes to the parent. \n", getpid(), data_to_send);
	exit(EXIT_SUCCESS);

}