class Solution {
public:
    void moveZeroes(vector<int>& nums) {
    	if (nums.size()==0) return;

    	int i=0;
    	int j=0;
    	for(auto & num:nums)
    	{
    		if(num==0)
    			j++;
    		else
    		{
    			swap(nums,i,j);
    			i++;
    			j++;
    		}
    	}
        
    }

private:
	void swap(vector<int> & nums, int i,int j)
	{
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
};