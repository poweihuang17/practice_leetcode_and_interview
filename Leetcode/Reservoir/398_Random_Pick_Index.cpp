class Solution {
public:
    Solution(vector<int> nums) :nums(nums){
		        
    }
    
    int pick(int target) {
        int index=0, count=0;
        for(int i=0;i<nums.size();i++)
        {
        	if(nums[i]==target)
        	{
        		count++;
        		if(random()%count==0) index=i;
        	}
        }
        return index;
    }
private:
	vector<int> nums;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */