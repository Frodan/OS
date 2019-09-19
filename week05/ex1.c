#include <stdio.h>
#include <pthread.h>

#define N 5

void *print(void* a){
    int* pointer = (int*)a;
    int id = *pointer;
    printf("Hello from thread: %d.\n", id);
    pthread_exit(0);
}

int main() {
    pthread_t tid[N];
    for (int i = 0; i < N; i++){
        pthread_create(&tid[i], NULL, print, &i);
        printf("Thread %d has created.\n", i);
        pthread_join(tid[i],NULL);
        printf("Thread %d exits.\n", i);
    }
    return 0;
}

