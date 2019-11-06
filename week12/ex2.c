#include<stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include <string.h>

int main(int argc, char* argv[]) {

    int in = fileno(stdin);
    int out;

    if (argc == 2){
        out = open(argv[1], O_RDWR | O_CREAT | O_TRUNC, 0777);
    }else if (argc == 3 && strcmp(argv[1], "-a") == 0){
        out = open(argv[2], O_RDWR | O_APPEND | O_CREAT, 0777);
    }else{
        printf("Usage:./ex2 filename or ./ex2 -a filename\n");
        return 0;
    }

    char byte;
    int status = read(in, &byte, 1);

    while(status != 0) {
        write(out, &byte, 1);
        status = read(in, &byte, 1);
    }

    close(in);
    close(out);
    return 0;
}