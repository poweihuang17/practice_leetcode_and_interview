class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0;
        int right=nums.size();
        int mid;
        while(left<right)
        {	
        	mid=(left+right)/2;
        	if(target>nums[mid])
        	{
        		left=mid+1;
        	}
        	else
        	{
        		right=mid;
        	}
        }
        return left;
    }
};