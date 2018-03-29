class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.size()==0) return 0;
        vector<int> table(nums.size()+1,0);
        for(int i=1;i<nums.size();i++)
        {
        	if(nums[i]>nums[i-1])
        		table[i]=table[i-1]+1;
        	else
        		table[i]=0;
        }
        return *max_element(table.begin(),table.end())+1;
    }
};