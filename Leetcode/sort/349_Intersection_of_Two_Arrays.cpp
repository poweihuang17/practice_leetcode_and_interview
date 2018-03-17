class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> check( nums1.begin(),nums1.end());
        vector<int> ans;
        for(auto  & num  : nums2)
        {
        	if(check.count(num))
        	{
        		ans.push_back(num);
        		check.erase(num);
        	}

        }
        return ans;
    }
};