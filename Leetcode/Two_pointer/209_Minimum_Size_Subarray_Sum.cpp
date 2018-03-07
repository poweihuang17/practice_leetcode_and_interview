class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.size()==1 && nums[0]>s)
        	return nums[0]>s;
        else if (nums.size()<=0)
        	return 0;
       	else
       	{
       		int left=0;
       		int right=0;
       		int result=INT_MAX;
       		while(right+1<=nums.size())
       		{
       			int temp=0;
       			for(int i=left;i<right+1;i++)
       			{
       				temp+=nums[i];
       			}
       			if(temp>=s)
       				{
       				result = result< (right-left+1)? result:right-left+1;
       				left++;
                    //cout<<"left shift";
       				}
       			else if (temp<s)
                {
                    right++;
                    //cout<<"right shift";
                }
       		}
       		return result==INT_MAX? 0: result;
       	}
    }
};