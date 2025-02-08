#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//===================== Dictionary in C =======================
#define MAX_SIZE 1000 // based on input array max size

int curr_size = 0 ; //current map elements
int keys[MAX_SIZE];
int values[MAX_SIZE];

// get the index of a key in the key array
int getIndex(int key){
    for (int i=0;i<curr_size;i++){
        if (keys[i]==key){
            return i;
        }
    }
    return -1; //key not found
}

// Functon to insert key-value pair into the map
void insert(int key){
    int index = getIndex(key);
    /* printf("%d\n",index); */
    if (index == -1){
        keys[curr_size] = key;
        values[curr_size] = 1;
        curr_size++;
    }
    else { // key found
        values[index]++ ;
    }
}

// Function to get the value of a key in the map
int get(int key){
    int index = getIndex(key);
    if (index==-1){
        return 0;
    }
    else {
        return values[index];
    }
}

// Function to print the map
void printMap(){
    for (int i=0;i<curr_size;i++){
        printf("%d: %d\n",keys[i],values[i]);
    }

}

//===================================================================

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
    int *ptra, *ptrb;
    int size = 0,i=0,len,number;

    char* token;

    FILE *fptr;
    fptr = fopen("input.txt","r");
    // Store the content of the file
    char inputs[20];
    // Read the content and print it
    while(fgets(inputs,20, fptr)) {
      /* printf("%s", inputs); */
      size++;
    }
    // Close the file
    fclose(fptr);

    ptra = (int*)malloc(size * sizeof(int));
    ptrb = (int*)malloc(size * sizeof(int));

    fptr = fopen("input.txt","r");
    // Read the content and print it
    while(fgets(inputs,20, fptr)) {
     
        /* printf("%s", inputs); */
        //Reading 1st list
        token = strtok(inputs," ");
        /* printf("%s\n",token); */

        len = strlen(token);
        ptra[i]=strtoi(token,len);

        // Reading the elements to the lists
        token = strtok(NULL," ");
        /* printf("%s\n",token); */
        len = strlen(token)-1;
        ptrb[i]=strtoi(token,len);

        // insert to dictionary
        insert(ptrb[i]);

        i++;
    }
    // Close the file
    fclose(fptr);
    
    // Sorting 
    /* qsort(ptra,size,sizeof(int),compare); */
    /* qsort(ptrb,size,sizeof(int),compare); */


    int ans = 0;

    for(int i=0;i<size;i++){
        /* printf("%d %d %d \n",ptra[i],ptrb[i],get(ptra[i])); */
        ans += get(ptra[i])*ptra[i];
    }
    /* printMap(); */
    printf("Answer: %d\n",ans);
    
    return 0;
}
