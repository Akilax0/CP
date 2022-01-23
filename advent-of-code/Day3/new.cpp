#include<bits/stdc++.h>
#include<fstream>

using namespace std;


class BSTNode{

	public:
		int Key;
		BSTNode * Left;
		BSTNode * Right;
		BSTNode * Parent;

		//BSTNode * BST::Insert(BSTNode * node, int key){
			//if(node == NULL){
				//node = new BSTNode;
				//node -> Key = key;
				//node -> Left = NULL;
				//node -> Right = NULL;
				//node -> Parent = NULL;
			//}

			//else if(node-> key < key){
				//node-> 

			//}

		//}
};


long to_dec(string s){
	long ans = 0;

	cout<<s<<"\n";

	for(int i=s.size()-1;i>=0;i--){
		ans += s[i]*pow(2,s.size()-i-1);
	}

	return ans;
}


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

	set<string> logs;

	while(!rfile.eof()) {
		rfile >> s;
		n++;
		logs.insert(s);
		for(int i=0;i<s.size();i++){
			if(s[i]=='1'){
				arr[i]++;	
			}
		}	
	}

	string A="";
	string B="";

	BSTNode* ra = NULL;
	BSTNode* rb = NULL;


	for(int i=0;i<12;i++){
		//cout<<A<<" "<<B<<"\n";
		if(arr[i] == n - arr[i]){
			arr[i] = 2;
			A = A + '1';
			B = B + '0';
		}else if(arr[i] > n - arr[i]){
			arr[i] = 1;
			A = A + '1';
			B = B + '0';
		}else{
			arr[i] = 0;
			A = A + '0';
			B = B + '1';
		}
	}

	//for(auto i:logs){
		//cout<<i<<"\n";
	//}

	long a=0,b=0;
	long l=0;

	bool fa = false;
	bool fb = false;

	cout<<A<<" "<<B<<"\n";

	//for(int i=12;i>=1;i--){
		//cout<<A.substr(0,i) << " "<<B.substr(0,i)<<"\n";
		//if(!fa && logs.find(A.substr(0,i)) != logs.end()){
			//cout<<A.substr(0,i)<<"\n";
			//a = to_dec(A.substr(0,i));	
			//fa = true;
		//}

		//if(!fb && logs.find(B.substr(0,i)) != logs.end()){
			//cout<<B.substr(0,i)<<"\n";
			//b = to_dec(B.substr(0,i));	
			//fb = true;
		//}
	//}

	cout<<to_string(a)<<" "<<to_string(b)<<"\n";
	cout<<to_string(a*b)<<"\n";

	return 0;
}	
