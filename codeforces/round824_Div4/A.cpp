#include<bits/stdc++.h>

// Sum 

using namespace std;

int main(){

	int t;
	cin>>t;

	while(t--){

	int a,b,c;
	vector<int> arr;

	cin>>a>>b>>c;
	arr.push_back(a);
	arr.push_back(b);
	arr.push_back(c);


	sort(arr.begin(),arr.end());

	if(arr[2] == arr[0] + arr[1]){
		cout<<"YES"<<endl;
	}else{	
		cout<<"NO"<<endl;

	}
	}
	
	return 0;
}
