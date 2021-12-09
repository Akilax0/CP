#include<bits/stdc++.h>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;

	// write your code here
	vector<std::pair<double,int>> order;



	int  n = weights.size();
	for(int i=0;i<n;i++){
		order.push_back(std::make_pair(values[i]/weights[i],i));
	}
	
	std::sort(order.begin(),order.end(),std::greater<double>());


	int i=0;
	while(capacity>0){
		int ava = std::min(weights[order[i].second],capacity);
		capacity = capacity - ava;
		value = ava*values[order[i].first];
	}


	return value;
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
