class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
        for(auto & num:nums)
        	sum+=num;
        int left_sum=0;
        for(int i=0;i<nums.size();i++)
        {
        	if(left_sum==(sum-nums[i]-left_sum))
        		return i;
        	left_sum+=nums[i];
        }
        return -1;
    }
};