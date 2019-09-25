#include <stdio.h>
#include <unistd.h>

#define MAXLEN 20

int main() {
    int pipefd[2];
    pipe(pipefd);
    char str1[MAXLEN] = "Hello, Pipe!";
    char str2[MAXLEN];

    write(pipefd[1], str1, MAXLEN);
    read(pipefd[0], str2, MAXLEN);
    printf("%s", str2);

    return 0;
}

