#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		int n;
		int a;
		cin>>n;
		vector<int> s;
		for(int j=0;j<n;j++){
			cin>>a;
			s.push_back(a);
		}
		sort(s.begin(),s.end());

		int c = 1;
		for(int k=0;k<n;k++){
			if(s[k]>=c){
				c++;
			}	
		}

		cout<<"Case #"<<i<<": "<<c-1<<endl;
	}

	return 0;
}
