#include<stdio.h>
int main() 
{
	
    char s[100];
	//scanning until new line detected
    scanf("%[^\n]%*c", s);
  	
    printf("Hello, World!\n");
    
    printf("%s",s);
    
 
    return 0;
}
      

