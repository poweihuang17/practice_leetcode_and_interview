class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

    	int start=0;
    	int end=0;
    	int count=0;
    	
    	
    	for(auto & num:nums)
    	{
    		if(num==0)
    			start=++end;
    		else
    			end++;
            count=max(count, end-start);
    	}
        
        return count;
        
    }
};