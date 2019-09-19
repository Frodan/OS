#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_IN_JAR 1


static int jar[MAX_IN_JAR];
static int top;
static int r;

static int producer_ready;
static int consumer_ready;

void consumer_sleep(){
    consumer_ready = 0;
}

void consumer_wakeup(){
    consumer_ready = 1;
}

void producer_sleep(){
    producer_ready = 0;
}

void producer_wakeup(){
    producer_ready = 1;
}
void *producer(void *vararg){
    while (1) {
        if (top == MAX_IN_JAR){
            producer_sleep();
        }
        while (1){
            if (producer_ready == 1){
                break;
            }
        };
        r++;
        jar[top] = r;
        top++;
        printf("Producer added %d, top is %d\n", r, top);
        consumer_wakeup();
    }
    pthread_exit(0);
}

void *consumer(void *varang){
    while (1){
        if (top == 0){
            consumer_sleep();
        }
        while (1){
            if (consumer_ready == 1){
                break;
            }
        };
        printf("Comsumer removed %d, top now is %d\n", jar[top - 1], top - 1);
        jar[top - 1] = 0;
        top = top - 1;
        producer_wakeup();
    }
    pthread_exit(0);
}

int main() {
    pthread_t th1, th2;
    top = 0;
    producer_wakeup();
    consumer_wakeup();
    pthread_create(&th1, NULL, producer, NULL);
    pthread_create(&th2, NULL, consumer, NULL);
    pthread_join(th1, NULL);
    pthread_join(th2, NULL);
    return 0;
}