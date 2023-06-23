#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // posix thread library

void *computation(void*);
int main() {
    pthread_t thread1; // create thread
    pthread_t thread2;

    long value1 = 1;
    long value2 = 2;

    pthread_create(&thread1, NULL, computation, (void*) &value1);
    pthread_join(thread1, NULL);

    pthread_create(&thread2, NULL, computation, (void*) &value2);
    pthread_join(thread2, NULL);
}

void *computation(void* add) {
    long sum = 0;
    long *add_num = (long*) (add);

    for(long i = 0; i <10000000; i++)
        sum += *add_num;

    return NULL;
}