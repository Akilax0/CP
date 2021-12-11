#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
	int start, end;
};


struct compare{
	bool operator()(Segment const & a,Segment const & b){
		return a.start <= b.start;
	}
};
vector<int> optimal_points(vector<Segment> &segments) {
	vector<int> points;
	
	sort(segments.begin(),segments.end(),compare());	


	//for(auto i: segments){
		//std::cout<<i.start<<" "<<i.end<<"\n";
	//}


	int i=0;
	int n = segments.size();
	while(i<n){
		//std::cout<<i<<"\n";
		Segment curr = segments[i];
		int l = curr.start;
		int r = curr.end;
		
		int index = i;
		while(r>=segments[i].start){
			if(l<=segments[i].start){
				l = segments[i].start;	
			}	
			if(r>=segments[i].end){
				r = segments[i].end;
			}
			i++;
		}
		if(index==i)i++;
		points.push_back(l);
	}

	////write your code here
	//for (size_t i = 0; i < segments.size(); ++i) {
		//points.push_back(segments[i].start);
		//points.push_back(segments[i].end);
	//}
	return points;
}

int main() {
	int n;
	std::cin >> n;
	vector<Segment> segments(n);
	for (size_t i = 0; i < segments.size(); ++i) {
		std::cin >> segments[i].start >> segments[i].end;
	}
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << "\n";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
}
