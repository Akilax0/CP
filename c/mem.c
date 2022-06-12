#include<stdio.h>
#include<stdlib.h>

int main(){

	//using memory addresses of the variables

	int age = 20;
	double gpa =3.3;
	char grade = 'A';

	// Prints memory of age variable
	printf("%p\n", &age);


	//Can store pointer in pointer variable 
	//Need to store in another variable
	int * pAge = &age;
	double * pGpa = &gpa;
	char * pGrade = &grade;

	//dref pointers in C
	//Grabb information at pointer
	
	printf("%p\n", pAge);
	printf("%d\n", *pAge);

	// &*age --> value
	// *&*age -- memory



	return 0;
}
