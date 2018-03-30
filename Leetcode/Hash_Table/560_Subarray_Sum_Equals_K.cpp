class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> prefix;
        prefix[0]=1;
        int sum=0;
        int ans=0;
        for(auto & num:nums)
        {
        	sum+=num;
        	if(prefix.count(sum-k))
        		ans+=prefix[sum-k];
        	prefix[sum]+=1;
        }
        return ans;
    }
};