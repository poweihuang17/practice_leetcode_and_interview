//Still not sure why it's tagged as DP....
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2) return false;

        unordered_map<int,bool> table;
        table[0]=true;
        int buffer=k!=0?nums[0]%k:nums[0];
        int sum=nums[0];
        for(int i=1;i<nums.size();i++)
    	{
    		sum+=nums[i];
    		if(table.count( k!=0?sum %k:sum) )
    			return true;
    		table[buffer]=true;
    		buffer=k!=0?(buffer+nums[i])%k:(buffer+nums[i]);
    	}
    	return false;
    }
};