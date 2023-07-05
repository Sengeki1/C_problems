#include <stdio.h>
#include <stdlib.h>
#define N 10

int main() {
    // Pointer array
    int arr[N], *ptr;

    // Inputting the array
    printf("Enter an Array: ");
    for(int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    ptr = &arr[N - 1];

    // Printing the reverse of the array
    for(int i = 0; i < N; i++) {
        printf("%d ", *ptr--);
    }
}