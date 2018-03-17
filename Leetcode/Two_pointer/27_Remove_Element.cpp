class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int i=0;
    	for(int k=0;k<nums.size();k++)
    	{
    		if(nums[k]==val)
    			continue;
    		else
    		{
    			swap(nums[k],nums[i]);
    			i++;
    		}
    	}

        return i;
    }
};