#include <stdlib.h> 
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        if (nums.size()<=0)
    		return 0;
    	else if (nums.size()==1)
    		return nums[0];
    	else if (nums.size()==2)
    		return nums[0]+nums[1];
    	
    	int result=nums[0]+nums[1]+nums[2];
    	sort(nums.begin(),nums.end());

    	for(int i=0;i<nums.size()-2;i++)
    	{
    		if(i>0 && nums[i]==nums[i-1])
    			continue;

    		else
    		{
    			int j=i+1, k=nums.size()-1;
    			while(j<k)
    			{
    				int s=nums[i]+nums[j]+nums[k];
    				if(s==target)
    				{
    					return s;
    				}
    				else if(s>target)
    				{
    					k-=1;
    					if(abs(s-target) < abs(result-target))
    						result=s;
    				}
    				else
    				{
    					j+=1;
    					if(abs(s-target) < abs(result-target))
    						result=s;
    				}
    			}
    		}

    	}
    	return result;
    }
};