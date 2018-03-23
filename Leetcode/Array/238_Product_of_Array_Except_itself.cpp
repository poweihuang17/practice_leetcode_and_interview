class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int rightsum=1;
        vector<int> leftarray(nums.size(),1);
        for(int i=1;i<nums.size();i++)
        {
        	leftarray[i]=leftarray[i-1]*nums[i-1];
        }
        for(int i=nums.size()-1;i>=0;i--)
        {
        	leftarray[i]=leftarray[i]*rightsum;
        	rightsum=rightsum*nums[i];
        }
        return leftarray;
    }
};