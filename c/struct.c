#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Student{
	char name[50];
	char major[50];
	int age;
	double gpa;
};

int main(){
	
	

	struct Student stu1;
	stu1.age = 22;
	stu1.gpa = 3.3;
	strcpy(stu1.name, "Jim");
	strcpy(stu1.major, "comp");
	

	printf("Details %s , %d , %lf, %s\n", stu1.name, stu1.age, stu1.gpa, stu1.major);

	//while loops 
	int index =6;
	while(index <= 5){
		printf("%d\n",index);
		index++;
	}

	//do while
	do{
		printf("%d\n",index);
		index++;
	}while(index <= 5);


	return 0;

}
