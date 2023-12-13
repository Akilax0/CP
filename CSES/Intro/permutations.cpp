#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){

	int n;
	cin>>n;

	if(n==1)cout<<"1"<<endl;
	else if(n>3){
		if(n%2!=0){
			for(int i=1;i<=n;i=i+2){
				cout<<i<<" ";			
			}
			for(int i=2;i<n;i=i+2){
				cout<<i<<" ";
			}
		}else{
			for(int i=2;i<=n;i=i+2){
				cout<<i<<" ";			
			}
			for(int i=1;i<n;i=i+2){
				cout<<i<<" ";
			}

		}
	}else{
		cout<<"NO SOLUTION"<<endl;
	}

	return 0;
}
