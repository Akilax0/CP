#include<stdio.h>

// Printing right aligned triangle 

int main(){
   

    int n;

    printf("Enter the size:\n");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            printf("   ");
        }

        for(int z=0;z<i+1;z++){
            printf("%3d",z+1);
        }

        printf("\n");
    }

    return 0;
}
