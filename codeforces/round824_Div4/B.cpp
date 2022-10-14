#include<bits/stdc++.h>
using namespace std;


// Increasing

int main(){

	int t;
	cin>>t;

	while(t--){
		
		int n,a;
		bool f = true;
		cin>>n;

		vector<int> arr;
		
		for(int i=0;i<n;i++){
			cin>>a;
			arr.push_back(a);
		}


		sort(arr.begin(),arr.end());

		for(int i=0;i<n-1;i++){
			if(arr[i]==arr[i+1]){
				f = false;
				break;
			}
		}

		if(f){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}

		
	

	}


	return 0;
}
