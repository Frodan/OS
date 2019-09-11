#include <stdio.h>
#include <unistd.h>

#define MAXLEN 100

int main() {
    char command[MAXLEN];
    fgets(command, MAXLEN, stdin);
    int n = fork();
    if (n == 0){
        char shell[] = "/bin/bash";
        char *args[] = {shell, "-c", command};
        char *env[] = {};
        execve(shell, args, env);
    }
    return 0;

}