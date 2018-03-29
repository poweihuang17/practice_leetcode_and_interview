class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x=0;
        for(auto & num:nums)
        {
        	x=x^num;
        }
        return x;
    }
};