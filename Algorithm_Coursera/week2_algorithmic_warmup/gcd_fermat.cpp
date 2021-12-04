#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}

int main(){
	int a = 357;
	int b = 234;

	cout<<gcd(a,b)<<"\n";


	return 0;
}
