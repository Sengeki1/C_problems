#include <stdlib.h>
#include <stdio.h>
#include <pthread.h> // posix thread library

void *computation(void*);
int main() {
    pthread_t thread1; // create thread

    long value1 = 1;
    // Run computation function in a separated thread
    pthread_create(&thread1, NULL, computation, (void*) &value1);
    /*
    
     We are passing in a pointer to our thread variable, the second argument is where we set
    attributes of the thread, the third argument is the function itself computation, and the
    fourth argument could be used to pass arguments to the computation function 
    
    */
   pthread_join(thread1, NULL); // Join the thread execution back with our main thread when its done
   /*

    The first argument is the thread we are joining with the main thread of execution and the
    second argument could be used to work with the return value from that function

   */
}
void *computation(void* add) {
    long *add_num = (long*) (add);
    printf("Add: %d\n", *add_num);
    return NULL;
}