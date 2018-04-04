class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> record;
        for(int i=0;i<nums.size();i++)
        	record[nums[i]].push_back(i);
        int max_value=0;
        for(auto & kv:record)
        	max_value=max(max_value,int(kv.second.size()));
        int shortest=nums.size();
        for(auto & kv:record)
        {
        	if(kv.second.size()==max_value)
        	{
        		shortest=min(shortest,kv.second.back()-kv.second[0]+1);
        	}
        }
        return shortest;
    }
};