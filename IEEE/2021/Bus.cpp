#include<bits/stdc++.h>
using namespace std;

void BFS(vector<pair<int,int>> ret, int u, int avoid){

	queue<pair<int,int>> q;
	q.push(make_pair(u,0));

	while(!q.empty()){
		
		pair<int,int> u = q.front();
		q.pop();

		int u_node = u.first;
		int u_dis  = u.second;

		for(auto v: paths[u_node]){
			if(v != avoid && !visited[v]){
				pair<int,int> temp = make_pair(v,u_dis+1);
				q.push(temp);
				ret.push(temp);
			}
		}
	}
}


int main(){
	int n;
	cin>>n;
	
	vector<vector<int>> paths(n+1);

	int cities[n];
		
	for(int i=0;i<n;i++){
		cin>>cities[i];
	}


	int u,v;
	for(int i=0;i<n-1;i++){
		cin>>u>>v;
		paths[u].push_back(v);
		paths[v].push_back(u);
	}

	int q,o;
	cin>>q;

	while(q--){
		int o,c;
		cin>>o;
		if(o==1)
			cin>>c;
		else{
			cin>>u>>v;
		}
//	cout<<o<<"\n";
//	if(o==1)
//		cout<<c<<"\n";
//	else
//		cout<<u<<" "<<v<<"\n";
		pair<int,int> avoid = check_path(u,v);

		vector<pair<int,int>> u_dis;
		vector<pair<int,int>> v_dis;

		

		BFS(u_dis,u,avoid.first);
		BFS(v_dis,v,avoid.second);


		for(auto i: u_dis){
			cout<<i.first<<" "<<i.second<<"\n";
		}

		
	}

	return 0;	
}
