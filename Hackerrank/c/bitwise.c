#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  
  int a=0,b=0,c=0;
  int temp_a,temp_b,temp_c;
  
  for(int i=1;i<n;i++){
      for(int j=i+1;j<=n;j++){
          temp_a = i&j;
          if(temp_a<k && temp_a > a){
              a = temp_a;
          }
          temp_b = i|j;
          if(temp_b<k && temp_b > b){
              b = temp_b;
          }
          temp_c = i^j;
          if(temp_c<k && temp_c > c){
              c = temp_c;
          }
      }
  }
  
  printf("%d\n%d\n%d\n",a,b,c);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

