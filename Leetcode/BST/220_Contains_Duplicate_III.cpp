class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size()==0) return false;
        else if(k==0) return false;
        
        set<long long> myset;
        for(int i=0;i<nums.size();i++)
        {
        	if(i>k) myset.erase(nums[i-k-1]);

        	auto pos=myset.lower_bound((long long)nums[i]-t);
        	if(pos!=myset.end() && *pos-nums[i]<=t) return true;
        	myset.insert(nums[i]);
        }
        return false;
    }
};