class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int total=0;
        nth_element(nums.begin(),nums.begin()+nums.size()/2,nums.end());
        int median=nums[nums.size()/2];
        for(auto & num:nums)
        {
            total+=abs(median-num);
        }
        return total;
    }
};