#include<stdio.h>
#include<stdlib.h>


int main(){

	double num1;
	double num2;
	char op;

	printf("Enter a number: ");
	scanf("%lf",&num1);

	printf("Enter operator ");
	scanf(" %c",&op);
	
	printf("Enter a number: ");
	scanf("%lf",&num2);


	if(op == '+')
		printf("%f", num1 + num2);
	else if(op == '-')
		printf("%f", num1 - num2);
	else if(op == '*')
		printf("%f", num1 * num2);
	else
		printf("Invlalid");
	printf("\n");

	switch(op){
	case '+':
		printf("Added\n");
		break;
	case '-':
		printf("Subbed\n");
		break;
	case '*':
		printf("Multi\n");
		break;
	default:
		printf("Told ya\n");
		break;
	}
}