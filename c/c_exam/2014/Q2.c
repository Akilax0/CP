#include<stdio.h>

int main(){
    long n;
    
    printf("Enter an integer in decimal number system\n");
    scanf("%ld",&n);

    int f;
    if(n<0){
        f=1;
        n *=-1;
    }else{
        f=0;
    }
    //int f = (n<0)?1:0;
    
    printf("%d in binary number system is: ",n);

    int ans[32];


    for(int i=0;i<32;i++){
        if(n>0){
            //printf("%d",n%2);
            ans[31-i] = n%2;
            n = n/2;
        }
        else{
            ans[31-i] = f;
            //printf("%d",f);
        }
    }

    for(int i=0;i<32;i++){
        printf("%d",ans[i]);
    }

    printf("\n");

    return 0;
}
