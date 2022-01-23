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

	while(!rfile.eof()) {
		rfile >> s >> n;
		
		cout<<s<<" "<<n<<"\n";
		if(s=="forward")
			hor += n;
		else if(s=="up")
			depth -=n;
		else
			depth +=n;

		//cout<<depth<<" "<<hor<<"\n"; 
	}

	//ToDo: refactor code so doesnt repeat last line 
	if(s=="forward")
		hor -= n;
	else if(s=="up")
		depth +=n;
	else
		depth -=n;
	cout<<depth * hor<<"\n";
	return 0;
}	
