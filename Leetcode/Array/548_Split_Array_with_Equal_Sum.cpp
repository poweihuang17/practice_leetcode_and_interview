
class Solution {
public:
    bool splitArray(vector<int>& nums) {
        if(nums.size()<7) return false;
        
        vector<int> sum(nums.size(),0);
        sum[0]=nums[0];
        

        for(int i=1;i<nums.size();i++)
        	sum[i]=sum[i-1]+nums[i];

        for(int j=3;j<nums.size()-3;j++)
        {
            unordered_map<int,bool> temp_sum;
        	for(int k=1;k<j-1;k++)
        	{
        		if(sum[k-1]==(sum[j-1]-sum[k]))
        			temp_sum[sum[k-1]]=true;
        	}

        	for(int k=j+2;k<nums.size()-1;k++)
        	{
        		if( (sum[k-1]-sum[j])==(sum[nums.size()-1]-sum[k]) && temp_sum.count(sum[k-1]-sum[j]))
        			return true;
        	}
        }
        return false;
    }
};