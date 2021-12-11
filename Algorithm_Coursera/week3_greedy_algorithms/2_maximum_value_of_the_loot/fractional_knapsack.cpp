#include<bits/stdc++.h>

using std::vector;


struct compare{
	bool operator()(std::pair<double,int> const & v1,std::pair<double,int> const & v2){
		return v1.first >= v2.first;
	}
};

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	// write your code here
	vector<std::pair<double,int>> order;

	int  n = weights.size();
	for(int i=0;i<n;i++){
		order.push_back(std::make_pair((double)values[i]/weights[i],i));
	}
	
	std::sort(order.begin(),order.end(),compare());

	//for(auto i: order){
		//std::cout<<i.first<<" "<<i.second<<"\n";
	//}

	int i=0;
	while(capacity>0 && i<=n){
		int ava = std::min(weights[order[i].second],capacity);
		capacity = capacity - ava;
		value =  value + ava*order[i].first;
		i++;
	}


	return round( value * 10000.0 ) / 10000.0;;
}

int main() {
	int n;
	int capacity;
	std::cin >> n >> capacity;
	vector<int> values(n);
	vector<int> weights(n);

	for (int i = 0; i < n; i++) {
		std::cin >> values[i] >> weights[i];
	}

	double optimal_value = get_optimal_value(capacity, weights, values);

	std::cout.precision(10);
	std::cout << optimal_value << std::endl;
	return 0;
}
