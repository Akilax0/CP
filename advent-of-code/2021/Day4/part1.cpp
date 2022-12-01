#include<bits/stdc++.h>
#include<fstream>
#include<sstream>

using namespace std;

int main(){

	const char* filename  = "./input.txt";
	ifstream rfile(filename);

	// Make sure the file stream is good
	if(!rfile) {
		cout << endl << "Failed to open file " ;
		return 1;
	}

	string n;
	int ans =0;
	int a;

	vector<int> order;
	int line_count = 0;
	while(getline(rfile,n)) {
		cout << n <<"\n" ;

		if(line_count == 0 ){
			stringstream s_stream(n);
			while(s_stream.good()){
				
				string substr;
				getline(s_stream, substr, ',');
				order.push_back(stoi(substr,nullptr,0));
			}
		}
	}

	for(auto i:order){
		cout<<i<<" ";
	}

	cout<<ans<<"\n";
	return 0;
}	
