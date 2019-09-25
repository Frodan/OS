#include <stdio.h>
#include <unistd.h>
#include <wait.h>


int main() {

    int pid = fork();

    if (pid != 0){
        sleep(10);
        kill(pid, SIGTERM);
    }
    else{
        while(1){
            printf("I am alive!\n");
            sleep(1);
        }
    }

    return 0;
}