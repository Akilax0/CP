#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, *arr, i;
    scanf("%d", &num);
    arr = (int*) malloc(num * sizeof(int));
    for(i = 0; i < num; i++) {
        scanf("%d", arr + i);
    }



    /* Write the logic to reverse the array. */
    
    int a,b;
    int h = num/2;
    for(int j=0;j<h;j++){
        a = *(arr + num - j -1);
        *(arr + num - j -1) = *(arr + j);
        *(arr + j) = a;
    }
    
    

    for(i = 0; i < num; i++)
        printf("%d ", *(arr + i));
    return 0;
}
