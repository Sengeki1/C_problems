#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int n, element, sum = 0;
    scanf("%d", &n);
    
    int *arr = (int*)malloc(n * sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", &element);
        arr[i] = element;
        sum += arr[i];
    }
    
    printf("%d\n", sum);
    
    free(arr);
    return 0;
}