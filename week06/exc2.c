#include <stdio.h>
#include <unistd.h>
#include <wait.h>

#define MAXLEN 20

int main() {
    int pipefd[2], pid;
    pipe(pipefd);
    char str1[MAXLEN] = "Hello, Pipe!";
    char str2[MAXLEN];
    pid = fork();
    if (pid != 0){
        write(pipefd[1], str1, MAXLEN);
        wait(NULL);
    }
    else{
        read(pipefd[0], str2, MAXLEN);
        printf("%s", str2);
    }

    return 0;
}