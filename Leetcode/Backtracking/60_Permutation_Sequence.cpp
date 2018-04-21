class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n,0);
        for(int i=0;i<nums.size();i++)
        	nums[i]=i+1;
        
        for(int i=0;i<k-1;i++)
        {

        	nextPermutation(nums);
        }
        return buildstring(nums);

    }

    string buildstring(vector<int> & nums)
    {
    	string s(nums.size(),'0');
    	for(int i=0;i<nums.size();i++)
    		s[i]+=nums[i];
    	return s;
    }

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