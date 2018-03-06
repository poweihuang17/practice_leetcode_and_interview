#include <unordered_map>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashTable;
        unordered_map<int,int>::iterator iter;
        vector <int> result(2);

        for(int i=0;i<nums.size();i++)
        {
        	int x=nums[i];
        	iter=hashTable.find(target-x);
        	if(iter!=hashTable.end())
        	{
        		result[0]=iter->second;
        		result[1]=i;
        	}
        	else
        	{
        		hashTable[nums[i]]=i;
        	}
        }

        return result;
    }
};