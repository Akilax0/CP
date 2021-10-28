#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	while(t--){

		string s;
		cin>>s;
		if(s.size() > 10){
			s = s[0] + to_string(s.size()-2) + s.back();
		}

		cout<<s<<"\n";
	}

	return 0;
}
