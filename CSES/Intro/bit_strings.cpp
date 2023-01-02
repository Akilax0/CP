#include<bits/stdc++.h>

#define ll long long
#define ld long double

#define M 1000000007
using namespace std;


ll solve(ll n,ll a){

    if(n==0)
        return a;

    a = (a * 2)%M;
    n--;
    return solve(n,a);
}

int main(){

	ll n;
	cin>>n;

	cout<<solve(n,1)<<endl;

	return 0;
}
