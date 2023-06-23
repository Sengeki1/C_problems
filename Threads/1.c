#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // posix thread library

void *computation(void*);
int main() {
    pthread_t thread1; // create thread
    pthread_t thread2;

    long value1 = 1;
    long value2 = 2;

    // Run computation function in a separated thread
    pthread_create(&thread1, NULL, computation, (void*) &value1);
    pthread_create(&thread2, NULL, computation, (void*) &value2);
    /*
    
     We are passing in a pointer to our thread variable, the second argument is where we set
    attributes of the thread, the third argument is the function itself computation, and the
    fourth argument could be used to pass arguments to the computation function 
    
    */
    pthread_join(thread1, NULL); // Join the thread execution back with our main thread when its done
    pthread_join(thread2, NULL);
   /*

    The first argument is the thread we are joining with the main thread of execution and the
    second argument could be used to work with the return value from that function

   */
}
void *computation(void* add) {
    long sum = 0;
    long *add_num = (long*) (add);
    for(long i = 0; i <10000000; i++)
        sum += *add_num;

    return NULL;
}