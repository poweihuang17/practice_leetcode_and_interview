class Solution {
public:
    void wiggleSort(vector<int>& nums) {
       if(nums.size()==0) return;
       for(int i=0;i<nums.size()-1;i++)
       {
       	if(i%2==0 && nums[i+1]<nums[i])
       		swap(nums,i,i+1);
       	else if(i%2==1 && nums[i+1]>nums[i])
       		swap(nums,i,i+1);
       } 
    }

private:
	void swap(vector<int> & nums, int i, int j)
	{
		int temp=nums[i];
		nums[i]=nums[j];
		nums[j]=temp;
	}
};