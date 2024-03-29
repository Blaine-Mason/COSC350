// Blaine Mason

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <string.h>

char* convIntToStr(int x){
    int temp = x;
    int counter = 0;
    while(temp > 0){
        counter++;
        temp /= 10;
    }
    char* strn = calloc(counter + 1, sizeof(char));
    for(int i = counter - 1; i >= 0; i--){
        strn[i] = (x%10) + '0';
        x /= 10;
    }
    return strn;
}

int new_atoi(char* str, int size){
    int ret = 0, i = 0;
    for(; i < size; i++){
        ret = (ret * 10) + (str[i] - 48);
    }
    return ret;
}

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
    printf("Before addition %d\n", num);
    num += 100;
    printf("After addition %d\n", num);
    write(1, convIntToStr(num), i);
    puts("");
    return 0;
}
