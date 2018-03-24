class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
    	sort(nums.begin(),nums.end());
    	vector<vector<int>> res;
    	permute(nums,0,nums.size(),res);
        return res;
    }

    void permute(vector<int> nums, int i, int j, vector<vector<int>> & res)
    {
    	if(i==j-1)
    	{
    		vector<int> r=nums;
    		res.push_back(r);
    		return;
    	}
    	for(int k=i;k<j;k++)
    	{
    		if(i!=k && nums[i]==nums[k]) continue;
    		swap(nums[i],nums[k]);
    		permute(nums,i+1,j,res);
    	}
        return ;
    }
};