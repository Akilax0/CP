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
	int n=0;
	int arr[12];
	memset(arr,0,sizeof(arr));
	while(!rfile.eof()) {
		rfile >> s;
		n++;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				arr[i]++;	
			}
		}	
	}


	long a,b;
	long l=0;

	for(int i=11;i>=0;i--){

		if(arr[i] > n/2){
			a += 1*pow(2,12-i-1);
		}
		else{
			
			b += 1*pow(2,12-i-1);
		}
	}
	cout<<a<<" "<<b<<"\n";
	cout<<a*b<<"\n";

	return 0;
}	
