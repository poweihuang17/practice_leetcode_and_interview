class Solution {
public:
    int missingNumber(vector<int>& nums) {
    	int find=0;
    	int i=0;
        for(i=0;i<nums.size();i++)
        	find=find ^ i ^ nums[i];
        return find^i;
    }
};