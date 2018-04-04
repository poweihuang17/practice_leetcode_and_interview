class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int max_diff=INT_MIN;
        

        int max_now=-10001;
        int min_now=10001;

        for(int i=0;i<arrays.size();i++)
        {
        	max_diff=max(max_diff,max_now-arrays[i][0]);
        	max_diff=max(max_diff,arrays[i].back()-min_now);

        	max_now=max(max_now,arrays[i].back());
        	min_now=min(min_now,arrays[i][0]);
        }
        return max_diff;
    }
};