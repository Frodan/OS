#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include <stdlib.h>

int main() {
    int pipefd[2], pid1, pid2;
    int status = 1;
    pipe(pipefd);

    pid1 = fork();
    if (pid1 == 0){
        int pid;
        read(pipefd[0], &pid, 4);
        printf("Child 1 get pid of Child 2: %d\n", pid);
        sleep(5);
        printf("Child 1 kills Child 2\n");
        kill(pid, SIGSTOP);
        exit(0);
    }
    else{
        pid2 = fork();
        if (pid2 == 0){
            while(1){
                printf("Child 2 is alive!\n");
                sleep(1);
            }
        }
        printf("Parent see %d and %d pids as childs\n", pid1, pid2);
        write(pipefd[1], &pid2, 4);
        waitpid(pid2, NULL, 0);
    }
    return 0;
}