class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()/2;i++)
            sum+=nums[i<<1];
        return sum;
    }
};