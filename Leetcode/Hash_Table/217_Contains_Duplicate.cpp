class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,bool> table;
        for(auto & num:nums)
        	{
        		if(table[num]==false)
        			table[num]=true;
        		else
        			return true;
        	}
        return false;
    }
};