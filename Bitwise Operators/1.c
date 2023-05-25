#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Complete the following function.
void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int a, b;
  int and, or, xor;
  int maxAND = 0, maxOR = 0, maxXOR = 0;

  if(n >= 2 && n <= 1000){
    if(k >= 2 && k <= n){
      for(a = 1; a <= k; a++){
        for(b = a + 1; b <= n; b++){
          and = a & b;
          if(and < k && and > maxAND) maxAND = and;
          or = a | b;
          if(or < k && or > maxOR) maxOR = or;
          xor = a ^ b;
          if(xor < k && xor > maxXOR) maxXOR = xor;
        }
      }
    }
  }
  printf("%d\n", maxAND);
  printf("%d\n", maxOR);
  printf("%d\n", maxXOR);
}


int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
