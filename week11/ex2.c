#include <stdlib.h>
#include <stdio.h>
#include <zconf.h>

int main() {
    char* buf = malloc(256);
    setvbuf(stdout, buf, _IOFBF, sizeof buf);

    printf("H");
    sleep(1);
    printf("e");
    sleep(1);
    printf("l");
    sleep(1);
    printf("l");
    sleep(1);
    printf("o");

    return 0;
}

