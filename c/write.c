
#include<stdio.h>
#include<stdlib.h>

int main(){
	// w,a,r
	FILE * fpointer = fopen("test.txt","a");

	//writes to file
	//overwrites file
	fprintf(fpointer, "Akila , asa\n");

	fclose(fpointer);


	//Reading Files
	char line[255];
	FILE * fpointer1 = fopen("test.txt","r");

	//reads first line 
	fgets(line, 255, fpointer1);
	printf("%s",line);

	fclose(fpointer1);
	return 0;
}
