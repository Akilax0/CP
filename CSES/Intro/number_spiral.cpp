#include<bits/stdc++.h>

#define ll long long

using namespace std;

ll solve(ll a, ll b){

	ll c = max(a,b);

	if(c%2==0){
		if (b==1)
			return c*c;
		else if (a < c)
			return solve(c,c) - (c-a); 
		else if (a == c)
			return (c*c - (b-1));
	}else{
		if (a==1){
			return c*c;
		}
		else if(b<c)
			return solve(c,c)-(c-b);
		else if(b==c)
			return c*c-(a-1);
		
	}
}

int main(){

	int n;
	cin>>n;

	while(n--){
		ll a,b;

		cin>>a>>b;
		
		cout<<solve(a,b)<<endl;
	
	}

	return 0;
}
