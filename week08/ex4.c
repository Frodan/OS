#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    int size = 1024*1024*10;
    for(int i = 0; i < 10; i++){
        void *pointer = malloc(size);
        memset(pointer, 0, size);
        getrusage(RUSAGE_SELF, &usage);
        printf("Usage: %ld\n", usage.ru_maxrss);
        sleep(1);
    }
    return 0;
}
