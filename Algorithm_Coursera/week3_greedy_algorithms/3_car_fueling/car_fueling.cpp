#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::vector;
using std::max;

//int compute_min_refills(int dist, int tank, vector<int> & stops) {
	//int no_refills = 0;
	//int curr_refill = -1;
	//int n = stops.size();

	//while(curr_refill <= n){
		//int last_refill	 = curr_refill;
		//while(curr_refill <= n && stops[curr_refill + 1]-stops[last_refill] <= tank){
			//curr_refill ++;
		//}
		//if(curr_refill == last_refill){
			//return -1;
		//}
		//if(curr_refill <= n){
			//no_refills ++;	
		//}

	//}

	//// write your code here
	//return no_refills;
//}


int compute_min_refills(int dist, int tank, vector<int> & stops) {
	int no_refills = 0;
	int curr_refill = -1;
	int curr_dis = 0;

	stops.push_back(dist);
	int n = stops.size();

	while(curr_refill <= n){
		int last_refill	 = curr_refill;
		while(curr_refill <= n && stops[curr_refill + 1]-curr_dis <= tank){
			curr_refill ++;
		}
		if(curr_refill == last_refill){
			return -1;
		}
		if(curr_refill <= n){
			no_refills ++;	
			curr_dis = stops[curr_refill];
		}

	}

	// write your code here
	return no_refills;
}
int main() {
	int d = 0;
	cin >> d;
	int m = 0;
	cin >> m;
	int n = 0;
	cin >> n;

	vector<int> stops(n);
	for (size_t i = 0; i < n; ++i)
		cin >> stops.at(i);

	cout << compute_min_refills(d, m, stops) << "\n";

	return 0;
}
