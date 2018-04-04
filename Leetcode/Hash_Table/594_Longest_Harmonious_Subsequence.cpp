class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> table;
        int ret=INT_MIN;
        for(auto & i:nums)
        	table[i]++;

        for(auto &kv:table)
        {
        	if(table.count(kv.first-1))
        		ret=max(ret, kv.second+table[kv.first-1]);
        }
        return ret==INT_MIN? 0:ret;
    }
};