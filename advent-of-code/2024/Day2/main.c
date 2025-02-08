#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int compare(const void*a, const void* b){
    return (*(int*)a - *(int*)b);
}

int strtoi(char token[],int len){
    int number = 0;
    for(int j=0;j<len;j++){
      number = number * 10 + (token[j]-'0');
    }
    return number;
}

int main(){

    // Arrays to store the numbers
    int arr[10],len,i,ans=0;

    FILE *fptr;
    fptr = fopen("input.txt","r");

    // Store the content of the file
    char inputs[100];
    char *token;

    // Read the content and print it
    while(fgets(inputs,100, fptr)) {

        i = 0;
        /* printf("%s", inputs); */

        //Numbers saved to an array
        token = strtok(inputs," ");
        while(token != NULL){
            /* printf("%s\n", token); */
            len = strlen(token);
            arr[i]= strtoi(token,len);
            i++;
            token = strtok(NULL, " \n");
        }

        /* printf("Numbers as ints: "); */
        /* for(int j=0;j<i;j++){ */
        /*     printf("%d ",arr[j]); */
        /* } */
        /* printf("\n"); */

        bool flag = true;

        if (arr[0]>arr[1]){
            for(int j=0;j<i-1;j++){
               if(arr[j]<arr[j+1] || (arr[j]-arr[j+1])>3 || (arr[j]-arr[j+1])<1){
                   flag = false;
                   break;
               }
            }
        }
        else if (arr[0]<arr[1]){
            for(int j=0;j<i-1;j++){
               if(arr[j]>arr[j+1] || (arr[j+1]-arr[j])>3 || (arr[j+1]-arr[j])<1){
                   flag = false;
                   break;
               }
            }
        }
        else{
            continue;
        }

        if(flag==true){
            ans++;
        }
    }
    // Close the file
    fclose(fptr);

    printf("Answer: %d \n",ans);

    
    return 0;
}
