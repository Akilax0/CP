#include<bits/stdc++.h>
#include<fstream>

using namespace std;

int main(){

	const char* filename  = "./input.txt";
	ifstream rfile(filename);


	// Make sure the file stream is good
	if(!rfile) {
		cout << endl << "Failed to open file " ;
		return 1;
	}

	long n = 0;
	int ans =0;

	long prevtot=0;
	long tot=0;

	long c=0;

	
	vector<long> v;
	while(!rfile.eof()) {
		rfile >> c;
		v.push_back(c);
		
	}
	for(auto i: v){
		cout<<i<<"\n";
	}
	tot = v[0]+v[1]+v[2];
	for(long i=0;i<v.size()-1;i++){
		prevtot = tot;
		tot = tot + v[i] - v[i-3];
		if(prevtot < tot){
			ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}	
