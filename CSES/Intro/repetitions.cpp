#include<bits/stdc++.h>

#define ll long long

using namespace std;


int main(){

	string s;
	cin>>s;

	char c = s[0];
	ll ct = 1;
	ll m = 1;

	for(ll i=1;i<s.size();i++){
		if(c==s[i])ct++;
		else{
			c = s[i];
			m = max(m,ct);
			ct=1;
		}
	}

	m = max(m,ct);

	cout<<m<<endl;
	return 0;
}
