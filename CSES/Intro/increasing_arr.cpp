#include<bits/stdc++.h>

#define ll long long

using namespace std;


int main(){

	int n;
	ll a,b;
	cin>>n;

	ll ans = 0;
	cin>>a;
		
	for(int i=1;i<n;i++){
		cin>>b;
		//cout<<a<<" "<<b<<" "<<a-b<<" ";
		if(b<a){
			ans += (a-b);
		}else{
			a = b;
		}
		//cout<<endl;
		
	}

	cout<<ans<<endl;
	return 0;
}
