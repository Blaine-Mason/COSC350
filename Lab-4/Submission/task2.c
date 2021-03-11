// Blaine Mason

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>
//Nice Guy
int convIntToStr(char * str, int x){
    sprintf(str, "%d", x);
    return (strlen(str));
}

int new_atoi(char* str, int size){
    int ret = 0, i = 0;
    for(; i < size; i++){
        ret = (ret * 10) + (str[i] - 48);
    }
    return ret;
}
//Nice Guy
int main(int argc, char* argv[]){
    int inFile = open(argv[1], O_RDONLY);
    char str[80], buf;
    int i = 0;

    while(read(inFile, &buf, 1)){
        if((int)buf >= 48 && (int)buf <= 57){
            str[i] = buf;
            i++;
        }

    }

    close(inFile);
    int num = new_atoi(str, i);
    num += 10;
    convIntToStr(str, num);
    write(1, str, i);
    return 0;
}
