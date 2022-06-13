#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char c;
    char str[100];
    char line[255];
    
    scanf("%c",&c);
   
    scanf("%s",str);
    scanf(" %[^\n]%*c",line);
    printf("%c\n",c);
    printf("%s\n",str);
    printf("%s",line);
    
    return 0;
}

