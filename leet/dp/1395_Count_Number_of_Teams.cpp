/**
 *	There are n soldiers standing in a line. Each soldier is assigned a uni		que rating value.

	You have to form a team of 3 soldiers amongst them under the following 		rules:

	Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
	A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
	Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
 *
 * */

class Solution {
public:
    int numTeams(vector<int>& rating) {
        
        int teams = 0;
        
        for(int i=1;i<rating.size()-1;i++){
            
            int leftless = 0;
            int rightGreater = 0;
            
            int leftGreater = 0;
            int rightless = 0;
        
            for(int j = i-1 ;j>=0;j--){
                if(rating[i] > rating[j])
                    leftless++;
                else
                    leftGreater++;
            }
            
            for(int j = i+1;j<rating.size();j++){
                if(rating[i]< rating[j])
                    rightGreater++;
                else
                    rightless++;
                
            }
            
            teams += (leftless*rightGreater) + (leftGreater * rightless);
            
        }
        
        return teams;
    }
};
