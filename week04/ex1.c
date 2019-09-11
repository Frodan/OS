#include <stdio.h>
#include <unistd.h>

int main() {
    int n = fork();
    if (n == 0){
        printf("Hello from child %d\n", n);
    }else{
        printf("Hello from parent %d\n", n);
    }
    return 0;
}
/*
 * fork() returns different result for different threads.
 * For child thread it will always return 0,
 * for parent - some integer != 0.
 */