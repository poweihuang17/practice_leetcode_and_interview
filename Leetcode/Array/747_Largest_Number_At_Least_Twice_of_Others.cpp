class Solution {
public:
    int dominantIndex(vector<int>& nums) {
    	int i;
    	int res;
    	res=max_element(nums.begin(),nums.end())-nums.begin();
    	i=nums[res];
    	for(auto & num:nums)
    	{
    		if(num!=i && num*2>i)
    			return -1;
    	}

    	return res;
    }
};