#include<stdio.h>

//printing symetrical number triangle
//           1
//         2 3 2
//       3 4 5 4 3
//

int main(){

    int n;

    printf("Enter N: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf("   ");
        }
        for(int j=0;j<i+1;j++){
            printf("%3d",i+1+j);
        }
        for(int j=i-1;j>=0;j--){
            printf("%3d",i+1+j);
        }

        printf("\n");
    }
    return 0;
}
