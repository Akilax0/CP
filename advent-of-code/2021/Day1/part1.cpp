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
	int a;
	while(!rfile.eof()) {
		a = n;
		rfile >> n;
		if( a == 0 || a < n ){
			ans++;
		}	

		//cout << n << "\n";
	}

	cout<<ans<<"\n";
	return 0;
}	
