#include<bits/stdc++.h>
using namespace std;

int main(){
	int l;
	cin>>l;
	char a;
	double b;


	unordered_map<char,double> alph;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		alph[a]=b;
	}

	string s;
	cin>>s;

	char prev='0';
	for(int i=0;i<s.length();i++){
		if(s[i]==prev){
			continue;
		}
		

		prev = s[i];
	}


	return 0;
}
