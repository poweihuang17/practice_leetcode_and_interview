class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
        	int index=abs(nums[i]);
        	if(nums[index-1]>0)
        		nums[index-1]=-nums[index-1];
        }
        vector<int> ans;
        for(int j=0;j<nums.size();j++)
        {
        	if(nums[j]>0)
        		ans.push_back(j+1);
        }
        return ans;
    }
};