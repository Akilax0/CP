#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char *s;
    s = malloc(1024 * sizeof(char));
    scanf("%[^\n]", s);
    s = realloc(s, strlen(s) + 1);
    //Write your logic to print the tokens of the sentence here.
    
    int s_len = strlen(s);
 
    int c,i=0,j=0;
    char w[100];
    while(i<s_len){
        c = *(s+i);
        if(c==' ' || c =='\n' || c==EOF){
            w[j]='\0';
            printf("%s\n",w);
            memset(w, 0, sizeof(w));
            j=0;
        }
        else{
            w[j]=c;
            j++;
            // printf("%c\n",c);
        }
        i++;
    }
    
    if(j>0){
        printf("%s\n",w);
    }
    return 0;
}
