#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    char *s;
    s = malloc(1024*sizeof(char));
    scanf("%s",s);
    s = realloc(s,strlen(s)+1);
    
    int s_len = strlen(s);
    int c;
    int i=0;
    
    int count[10];
    memset(count,0,sizeof(count));
    
    while(i<s_len){
        c = *(s+i);
        int a = c-'0';
        // printf("%d\n",a);
        if(a<10 && a>=0)
            count[a]++;
        
        i++;
        
    }
    
    for(int i=0;i<10;i++){
        printf("%d ",count[i]);
    }
    printf("\n");
    return 0;
}

