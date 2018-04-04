class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
    	int sum=0;
    	int duplicate;        
        for(int i=0;i<nums.size();i++)
        {
            int t=abs(nums[i]);
        	if(nums[t-1]<0)
        		duplicate=t;
        	else
        		nums[t-1]=-nums[t-1];

        	sum+=abs(nums[i]);
        }
        vector<int> ret(2);
        ret[0]=duplicate;
        //cout<<sum;
        ret[1]=duplicate+nums.size()*(nums.size()+1)/2-sum;
        return ret;
    }
};