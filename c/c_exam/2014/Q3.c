#include<stdio.h>

unsigned int reverseNum(unsigned int);
int isPalinNum(unsigned int);

int main(){
    unsigned int n, count=1;

    printf("Enter a number: ");
    scanf("%u",&n);

    //until palindrom or iterate 20 times
    while(!isPalinNum(n) && (count <= 20)){
        n = n + reverseNum(n);
        count++;
    }

    if(count > 20)
        printf("Lychrel process didn't work\n");
    else 
        printf("It took %u iteration(s)\n",count);

    return 0;
}


unsigned int reverseNum(unsigned int n){
    unsigned int ans=0;

    while(n>0){
        ans = ans*10 + n%10;
        n = n/10;
    }

    return ans;
}


int isPalinNum(unsigned int n){
    if(reverseNum(n) ==n){
        return 1;
    }

    return 0;
}
