#include<bits/stdc++.h>
using namespace std;

int get_gold(int id){
	return id;
}


int main(){

	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> path(n);
	unordered_map<ULL,int> gold;
	bool visited[n];
	memset(visited,false,sizeof(visited));
	
	unsigend long long id;
	for(int i=0;i<n;i++){
		cin>>id;
		gold[id] = get_gold(id);

	}

	return 0;
	

}
