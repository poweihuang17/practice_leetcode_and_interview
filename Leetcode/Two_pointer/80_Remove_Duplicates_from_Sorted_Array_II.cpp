class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_map<int, int> table;
        if(nums.size()<2) return nums.size();
        int id=1;
        table[nums[0]]=1;
        for(int i=1;i<nums.size();i++)
        {
        	if(nums[i]!=nums[i-1])
        		{
        			table[nums[i]]=1;
        			nums[id++]=nums[i];
        		}
        	else
        	{
        		if(table.count(nums[i])==0) 
	        		{
	        			table[nums[i]]=1;
	        			nums[id++]=nums[i];
	        		}
	        	else if (table[nums[i]]==1)
	        		{
	        			table[nums[i]]=2;
	        			nums[id++]=nums[i];
	        		}
	        	
        	}
        	
        }
        return id;
    }
};