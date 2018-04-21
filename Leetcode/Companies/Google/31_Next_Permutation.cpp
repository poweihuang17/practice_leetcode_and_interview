class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int index=-1;
        for(int i=nums.size()-1;i>=1;i--)
        {
        	if(nums[i]>nums[i-1])
        		{
        			index=i-1;
        			break;
        		}
        }
        if(index==-1)
        	{
        		reverse(nums.begin(),nums.end());
        		return;
        	}
        int l=-1;
        for(int i=nums.size()-1;i>=0;i--)
        {
        	if(nums[i]>nums[index])
        		{
        			l=i;
        			break;
        		}
        }
        swap(nums[l],nums[index]);
        reverse(nums.begin()+index+1,nums.end());
        
    }
};