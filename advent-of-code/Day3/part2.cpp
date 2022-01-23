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

	set<string> c1; //One for 1 when equal
	set<string> c2; // One for 0 when equal



	while(!rfile.eof()) {
		rfile >> s;
		c1.insert(s);
		c2.insert(s);

		n++;
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				arr[i]++;	
			}
		}	
	}
	



	string a = "";
	string b = "";

	string ca,cb;
		
	for(int i=0;i<12;i++){
		cout<<a<<" "<<b<<"\n";
		if(arr[i] > n/2){
			a += '1';
			b += '0';
		}else if(arr[i] < n/2){
			b += '1';
			a += '0';
		}else{
			a += '1';
			b += '0';
		}			


		if(c1.size() >  1){
			for(auto j: c1){
				if(j.substr (0,i) != a)
					c1.erase(j);
				ca = a;

			}
		}
		//if(c2.size() > 1){
			//for(auto j: c2){
				//if(j.substr (0,i) != b)
					//c2.erase(j);
			//}

			//cb = b;
		//}
	}

	
	cout<<ca<<" "<<cb<<"\n";

	long A =0;
	long B =0;


	for(int i=ca.size()-1;i>=0;i--){
		A += ca[i]*pow(2,i);
	}

	for(int i=cb.size()-1;i>=0;i--){
		B += cb[i]*pow(2,i);
	}
		
	cout<<A * B<<"\n";

	return 0;
}	
