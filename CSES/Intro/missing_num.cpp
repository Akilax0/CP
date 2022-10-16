#include<bits/stdc++.h>

#define ll long long

using namespace std;


int main(){

	set<ll> s;
	ll n,a;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		s.push(a);
	}

	for(int i=1;i<=n;i++){
		if(arr[i]==0){
			cout<<i<<endl;
			break;
		}
	}

	return 0;
}
