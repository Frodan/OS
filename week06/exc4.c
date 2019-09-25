/*
 * The signals SIGSTOP and SIGKILL cannot be caught or ignored,
 * so handlers for them will never be called.
 * But USR1 signal we can catch, after command `kill -SIGUSR1 <pid>`
 * we will see text from handler.
 */
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>


void kill_handler(int sig){
    printf("\nSIGKILL detected.\n");
    exit(0);
}

void stop_handler(int sig){
    printf("\nSIGSTOP detected.\n");
    exit(0);
}

void usr1_handler(int sig){
    printf("\nUSR1 detected.\n");
    exit(0);
}

int main() {
    int pid = getpid();
    printf("My pid: %d\n", pid);
    signal(SIGKILL, kill_handler);
    signal(SIGSTOP, stop_handler);
    signal(SIGUSR1, usr1_handler);
    while (1){};

    return 0;
}