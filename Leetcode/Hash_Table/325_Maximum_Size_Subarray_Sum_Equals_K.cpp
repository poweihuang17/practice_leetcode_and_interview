class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        
        unordered_map<int, int> prefix;
        prefix[0]=-1;
        int sum=0;
        int ans=0;
        int index=0;
        for(auto & num:nums)
        {
        	sum+=num;
        	if(prefix.count(sum-k))
        		ans=max(ans, index-prefix[sum-k]);
        	if (prefix.count(sum)==0)
        		prefix[sum]=index;
        	index++;
        }
        return ans;
    }
};