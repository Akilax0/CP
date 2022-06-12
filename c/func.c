#include<stdio.h>
#include<stdlib.h>

void sayHi(char name[], int age);

//if want to return data put here
//prototyping
double cube(double num);
	
int max(int num1,int num2);

int main(){

	sayHi("Akisa",12);
	printf("Answer: %.4f\n", cube(8));
	printf("Max: %d\n", max(12,31));
	return 0;
}

void sayHi(char name[], int age){
	
	printf("Hello %s , You are %d years old.\n", name,age);

}


double cube(double num){
	double result = num * num * num;
	return result;
}

int max(int num1,int num2){
	int result;
	if(num1 >= num2){
		result = num1;
	}else{
		result = num2;
	}

	return result;

}
