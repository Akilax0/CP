#include <iostream>

int get_change(int m) {
	//write your code here
	int a=0,b=0,c=0;
	if(m >=10){
		a = m / 10;
		m = m %10;
	}

	//std::cout<<m<<"\n";

	if(m >= 5){
		b = m / 5;
		m = m % 5;
	}

	//std::cout<<m<<"\n";
	//if(m>=1){
		//c = m/1;
		//m = m % 1;
	//}

	return a + b + m;
}

int main() {
	int m;
	std::cin >> m;
	std::cout << get_change(m) << '\n';
}
