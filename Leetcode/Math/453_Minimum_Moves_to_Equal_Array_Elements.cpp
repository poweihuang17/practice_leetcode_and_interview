class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        for(auto & num:nums)
        	sum+=(num);
        return sum-*min_element(nums.begin(),nums.end())*nums.size();
    }
};