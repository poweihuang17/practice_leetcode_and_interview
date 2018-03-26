class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(nums.size()<2) return 0;
        int sum=0;
        while(1)
        {
        	int count=0;
        	bool no_number=true;
        	for(int i=0;i<nums.size();i++)
        	{
        		if(nums[i]%2) count++;
        		if(nums[i]>0) no_number=false;
        		nums[i]=nums[i]/2;
        	}
        	sum+=count*(nums.size()-count);
        	if(no_number) return sum;
        }
    }
};