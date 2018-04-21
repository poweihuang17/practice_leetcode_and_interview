class Solution {
public:
    /**
     * @param nums: the arrays
     * @param k: the distance of the same number
     * @return: the ans of this question
     */
    string sameNumber(vector<int> &nums, int k) {
        // Write your code here
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-k;)
        {
        	for(int j=i+1;j<nums.size() && j<i+k;j++)
        	{
        		if(nums[j]==nums[i])
        			return "Yes";
        		i=j;
        	}
        }
        return "No";
    }
};

class Solution {
public:
    /**
     * @param nums: the arrays
     * @param k: the distance of the same number
     * @return: the ans of this question
     */
    string sameNumber(vector<int> &nums, int k) {
        // Write your code here
        unordered_map<int,vector<int>> index;
        for(int i=0;i<nums.size();i++)
            index[nums[i]].push_back(i);
        
        for(auto & kv:index)
            {
                for(int i=0;i<kv.second.size()-1;i++)
                    {
                        if(kv.second[i+1]-kv.second[i]<k)
                            return "YES";
                    }
            }
        return "NO";
    }
};