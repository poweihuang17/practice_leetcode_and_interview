class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

    	int start=0;
    	int end=0;
    	int count=0;
    	int count_one=0;
    	
    	for(auto & num:nums)
    	{
    		if(num==0)
    			count_one++;

    		if(count_one>1)
    		{
    			while(start<=end && count_one>1)
    			{
    				if(nums[start]==0)
    					count_one--;
    				start++;
    			}
    		}
    		count=max(count, end-start+1);
    		end++;
    	}
        
        return count;
    }
};