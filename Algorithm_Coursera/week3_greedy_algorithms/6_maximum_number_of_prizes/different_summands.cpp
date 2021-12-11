#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
	vector<int> summands;
	//write your code here
	int tot=0;

	int i=1;
	int prev = 0;
	while(tot < n){
		if(prev < i){
			tot +=i;
			prev = i;
			summands.push_back(i);
		}
		


		i++;
	}
	return summands;
}

int main() {
	int n;
	std::cin >> n;
	vector<int> summands = optimal_summands(n);
	std::cout << summands.size() << '\n';
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << ' ';
	}
}
