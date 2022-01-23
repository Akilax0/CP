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

	string s;
	long n = 0;
	int ans =0;
	long hor = 0;
	long depth = 0;

	vector<pair<string,long>> v;

	while(!rfile.eof()) {
		rfile >> s >> n;
		
		cout<<s<<" "<<n<<"\n";
		v.push_back(make_pair(s,n));	
	}

	long aim = 0;
	for(int i=0;i<v.size()-1;i++){
		
		s = v[i].first;
		n = v[i].second; 
		cout<<depth<<" "<<hor<<"\n";
		if(s=="forward"){
			hor += n;
			depth += aim*n;
		}
		else if(s=="up")
			aim -=n;
		else
			aim +=n;


	}

	cout<<depth * hor<<"\n";
	return 0;
}	
