class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,unordered_set<int>> table;
        for(int i=0;i<nums.size();i++)
        	{
        		for(auto & t:table[nums[i]])
        			if(abs(t-i)<=k) return true;
                table[nums[i]].insert(i);
        	}
        return false;
    }
};