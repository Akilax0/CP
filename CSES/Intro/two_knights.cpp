#include<bits/stdc++.h>

#define ll long long

using namespace std;

// total number of ways to place two knights
// for one knight n^2
// for second knight n^2 - 1
// (n^2)(n^2-1)/2
//
// total number of ways 
//  

void solve(ll n){
	for(ll i=1;i<=n;i++){
		ll totalPositions = (i*i) * (i*i-1)/2;
		ll attackPositions = 4*(i-1)*(i-2);
		cout<< totalPositions - attackPositions << endl;
	} 
}

int main(){

	ll n;
	cin>>n;

	solve(n);


	return 0;
}
