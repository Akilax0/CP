#include<bits/stdc++.h>

#define ll long long

using namespace std;


void solve(ll n){

	ll sum = (n * (n+1))/2;

	if( sum %2 ==0){
		cout<<"YES\n";	
		set<ll> s1,s2;
		ll target = sum/2;
		int t = n;
		for(int i=1;i<=n;i++){
			s1.insert(i);
		}
		while(s1.count(target)==0){
			target -= t;
			s2.insert(t);
			s1.erase(t);
			t--;
		}
		s1.erase(target);
		s2.insert(target);
		cout<<s1.size()<<endl;
		for(int z: s1){
			cout<<z<< " ";
		}
		cout<<s2.size()<<endl;
		for(int z: s2){
			cout<<z<< " "; 
		}



	}else{
		cout<<"NO\n";
	}
}

int main(){

	ll n;
	cin>>n;

	solve(n);

	return 0;
}
