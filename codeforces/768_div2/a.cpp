#include<bits/stdc++.h>
using namespace std;
int main(){

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		vector<int> a;
		vector<int> b;

		int x,y;

		int m_a=0,m_b=0;
		for(int i=0;i<n;i++){
			cin>>x;
			a.push_back(x);
		}
		for(int i=0;i<n;i++){
			cin>>x;
			if(x<a[i]){
				m_a = max(m_a,x);	
				m_b = max(m_b,a[i]);
			}else{
				m_a = max(m_a,a[i]);
				m_b = max(m_b,x);
			}

			//cout<<m_a<<" "<<m_b<<"\n";
		}

		

		cout<<m_a*m_b<<"\n";
	}

	return 0;
}
