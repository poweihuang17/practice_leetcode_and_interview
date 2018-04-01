//std vector copy
//https://stackoverflow.com/questions/2275076/is-stdvector-copying-the-objects-with-a-push-back
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> temp;
        backtrack(ret, temp, nums,0);

        return ret;
    }

private:

    void backtrack(vector<vector<int>> & ret, vector<int> & temp, vector<int> & nums, int i)
    {
    	ret.push_back(temp);
    	for(int k=i;k<nums.size();k++)
    	{
    		temp.push_back(nums[k]);
    		backtrack(ret, temp, nums,k+1);
    		temp.pop_back();
    	}
    }
};