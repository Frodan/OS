#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

void handler(int sig){
    printf("\nCtrl-C detected, process is terminating...\n");
    exit(0);
}

int main() {

    signal(SIGINT, handler);
    while (1){};

    return 0;
}