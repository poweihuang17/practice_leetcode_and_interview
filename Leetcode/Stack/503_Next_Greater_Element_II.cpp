class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
    	if(nums.size()==0) return vector<int>();

        unordered_map<int,int> table;
        stack<int> find_next;

        int max_value=*max_element(nums.begin(),nums.end());

        int i=0;
        while(table.size()<nums.size())
        {
        	
        	while(find_next.size() && nums[find_next.top()]<nums[i])
        		{
        			table[find_next.top()]=i;
        			find_next.pop();
        		}
        	if(nums[i]!=max_value) find_next.push(i);
            else table[i]=-1;
        	i=(i==nums.size()-1)?0:i+1;
        }
        vector<int> ret;
        for(int i=0;i<nums.size();i++)
        {
        	if(nums[i]==max_value) ret.push_back(-1);
        	else ret.push_back(nums[table[i]]);
        }
        return ret;
    }
};