#include<bits/stdc++.h>
using namespace std;

// Stripes

int main(){
	
	int n;
	cin>>n;

	while(n--){

		string s;
		vector<string> arr;
		for(int i=0;i<8;i++){
			cin>>s;
			arr.push_back(s);
		}


		for(int i=0;i<8;i++){
			s = "";
			for(int j=0;j<8;j++){
				s += arr[j][i];	
			}

			arr.push_back(s);
		}

		char ans;
		for(int i=0;i<16;i++){
			if(arr[i] == "RRRRRRRR"){
				ans = 'R';
			}else if(arr[i] == "BBBBBBBB"){
				ans = 'B';
			}
		}

		cout<<ans<<endl;
	}
	

	return 0;
}
