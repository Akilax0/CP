#include<stdio.h>
#include<stdlib.h>

int main(){
/* Print Statements */
	printf("Hello World!\n");

	printf("    /\\\n");
	printf("   /  \\\n");
	printf("  /    \\\n");
	printf(" /      \\\n");
	printf("/        \\\n");

/* Variables */
	char name[] = "Bobby"; 
	int age = 35;

	printf("There was a man named %s \n", name);
	printf("He was %d years old \n", age);
	
	age++;
	printf("%s becomes %d this year.\n",name,age);


/* Data Types */

	int  credits = 12;
	float weight = 50.1;
	double gpa = 3.6;
	char grade = 'A';
	//creating a string of characters
	char phrase[] = "Hello stranger!";

/* printf() revisited */

	//format specifier for data
	//int %d
	//string %s
	//char %c
	//decimal %f

/* Numbers */
	// int + int -> int
	// float + int -> float
	// int/int -> int
	// int/float -> float
	
	printf("%.2f\n", 12.123);

	// extra functions
	// pow(2,3) = 8
	// sqrt(36) = 6
	// ceil(36.3) = 37
	// floor(36.2) = 36


/* Constants */

	//cannot be modified
	const int NUM = 5;

	// Also direct values are considered as constants

/* User Input */
	printf("Enter age: ");
	//pointer to variable
	scanf("%d",&age);
	printf("You are %d years old.\n",age);

	// double read %lf
	// char %c
	// string 
	//	char name[20];
	//	scanf("%s",name);
	//	printf("Your name is %s\n",name);
	//
	//But scanf only gets until space
	//
	//fgets(name, 20, stdin);
	//
	//only for a string of characters
	//Also takes in the newline 
	
	
/* Arrays */

	return 0;
}
