#include<bits/stdc++.h>
#include<fstream>

typedef long long ll;

using namespace std;

int main(){


	const char* filename  = "./input.txt";
	ifstream rfile(filename);


	// Make sure the file stream is good
	if(!rfile) {
		cout << endl << "Failed to open file " ;
		return 1;
	}


	ll a,b,c,d;
	vector<vector<ll>> arr;
	while(!rfile.eof()) {
		rfile >> a >> b >> c >>d;
	
		//cout<<a<<b<<c<<d<<"\n";
		vector<ll> tmp = {a,b,c,d};

		//for(auto i: tmp){
			//cout<<i<<" ";
		//}
		//cout<<"\n";
		arr.push_back(tmp);
	}

	unordered_map<string,int> ma;	
	int ans = 0;
	

	for(int i=0;i<arr.size()-1;i++){
		//cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<"\n";


		ll x1 = arr[i][0];
		ll y1 = arr[i][1];
		ll x2 = arr[i][2];
		ll y2 = arr[i][3];
		

		if(x1==x2){
			ll ys = min(y1,y2);
			ll ye = max(y1,y2);
			
			for(ll k = ys ; k<= ye ; k++){
				string st = to_string(x1)+to_string(k);

				if(ma.find(st) == ma.end()){
					ma[st] = 0;
				}
				ma[st]++;
				if(ma[st]==2){
					ans++;
				}
				cout<<st<<" "<<ma[st]<<"\n";
			}
		}
		else if(y1==y2){
			ll xs = min(x1,x2);
			ll xe = max(x1,x2);
			
			for(ll k = xs ; k<= xe ; k++){
				
				string st = to_string(k)+to_string(y1);
				if(ma.find(st) == ma.end()){
					ma[st] = 0;
				}
				ma[st]++;
				if(ma[st]==2){
					ans++;
				}
				cout<<st<<" "<<ma[st]<<"\n";
			}
		}
		else{
			continue;
		}


	}
	
	cout<<ans;



	return 0;
}
