#include <unistd.h> 
 #include <fcntl.h> 
 #include <ctype.h> 
  
 int main () 
 { 
       umask(if (creat("foo",S_IRUSR |S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) <0)0200); 	       return 1;     umask(0440); 
    if (creat ("bar",S_IRUSR |S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH) <0)       return 1;     } return 0; 
