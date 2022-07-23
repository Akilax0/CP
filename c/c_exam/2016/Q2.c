#include<stdio.h>


// function takes string and returns long 


long string2long(char input[]);

int main(){

    char input[30];

    printf("Enter an integer: ");
    scanf("%s", input);

    printf("The integer you entered is %ld.\n",string2long(input));


    return 0;
}

long string2long(char a[]){
    
    int i=0,f=0;
    long res=0;

    if(a[i]=='-'){
      f=1;
      i++;
    }
    while(a[i]!='\0'){
        res = res*10 + (a[i]-'0'); 
        i++;
    }

    if(f)res*=-1;

    return res;

}
