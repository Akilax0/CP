#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{

    int n,i,j,k;
    scanf("%d", &n);
  	// Complete the code to print the pattern.
      
    for(i=0;i<(2*n-1)/2+1;i++){
        for(j=0;j<i;j++){
            printf("%d ",n-j);
        }
        for(k = i; k< 2*n-i-1;k++){
            printf("%d ",n-j);
        }
        for(int z=2*n-i-1;z<2*n-1;z++){
            printf("%d ",z+2-n) ;
        }
        printf("\n");
    }
    for(i=(2*n-1)/2+2;i<=2*n-1;i++){
        for(j=0;j<2*n-1-i;j++){
            printf("%d ",n-j);
        }
        for(k = 2*n-1-i;k<i;k++){
            printf("%d ",n-j);
        }
        for(int z=i;z<2*n-1;z++){
            printf("%d ",z+2-n) ;
        }
        printf("\n");
    }
    return 0;
}
