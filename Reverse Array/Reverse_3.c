#include <stdio.h>
#include <stdlib.h>
#define N 1000

int main() {
    int arr[N];

    int n;
    // Inputting the size of the array
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    // Inputting the array
    printf("Enter an array: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int rarr[N];
    // Reversing the array
    for (int i = 0; i < n; i++) {
        rarr[i] = arr[n - i - 1]; // copying from last index to 0 index and storing in a new array
    }

    printf("Reversed array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", rarr[i]);
    }

    return 0;
}