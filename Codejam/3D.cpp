#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	unsigned int c,m,y,k;

	for(int j=1;j<=t;j++){
		vector<unsigned int> col;
		vector<unsigned int> ans;
		for(int i=0;i<4;i++){
			col.push_back(1000000);
			ans.push_back(0);
		}

		for(int i=0;i<3;i++){
			cin>>c>>m>>y>>k;
			col[0] = min(col[0],c);
			col[1] = min(col[1],m);
			col[2] = min(col[2],y);
			col[3] = min(col[3],k);

			//cout<<col[0]<<" "<<col[1]<<" "<<col[2]<<" "<<col[3]<<endl;
		}

		unsigned int sum = 0;

		for(int i=0;i<4;i++){
			if(sum + col[i] >=1000000){
				ans[i] = 1000000 - sum;
				sum += col[i];
				break;
			}
			else{
				ans[i] = col[i];
				sum += col[i];
			}
		}
		
		if(sum < 1000000){
			cout<<"Case #"<<j<<": IMPOSSIBLE"<<endl;
		}
		else{

			cout<<"Case #"<<j<<": ";
			for(int i=0;i<4;i++){
				cout<<ans[i]<<" ";
			}
		}
		cout<<endl;
	}

	return 0;
}
