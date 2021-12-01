#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
	int n;
	cin>>n;


	vector<ll>ans(n);
	long a = 0;
	long b = 0;
	int temp;
	for(int i=0;i<n;i++){
		cin>>ans[i];
	}	

	sort(ans.begin(),ans.end());

	//cout<<ans[n-1]<<"\n";
	cout<<ans[n-2]*ans[n-1]<<"\n";


	return 0;

}
