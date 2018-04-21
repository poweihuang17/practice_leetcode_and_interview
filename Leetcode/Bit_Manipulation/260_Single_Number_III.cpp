class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int x=accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        x=x&-x;

        vector<int> rets{0,0};

        for(auto & num:nums)
        {
        	if((num&x)==0)
        		rets[0]^=num;
        	else
        		rets[1]^=num;
        }
        return rets;

    }
};