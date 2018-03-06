class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left=0, right=numbers.size()-1;
        vector<int> result;

        while (left<right)
        {
        	int sum=numbers[left]+numbers[right];
        	if( sum == target)
        	{
        		result.push_back(left+1);
        		result.push_back(right+1);
        		return result;
        	}
        	else if (sum> target)
        	{
        		right--;
        	}
        	else
        	{
        		left++;
        	}
        }

        return result;
    }
};