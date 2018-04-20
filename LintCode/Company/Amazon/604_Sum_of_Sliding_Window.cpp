class Solution {
public:
    /**
     * @param nums: a list of integers.
     * @param k: length of window.
     * @return: the sum of the element inside the window at each moving.
     */
    vector<int> winSum(vector<int> &nums, int k) {
        if(nums.size()==0) return {};
        // write your code here
        vector<int> ret;
    	int sum=0;
        for(int i=0;i<k;i++)
        	sum+=nums[i];
        for(int i=0;i<=nums.size()-k;i++)
        {
        	ret.push_back(sum);
        	if(i+k==nums.size()) return ret;
        	sum+=nums[i+k];
        	sum-=nums[i];
        }
    }
};