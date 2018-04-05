class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        stack<int> mystack;
        unordered_map<int,int> table;

        for(auto & num:nums)
        {
        	while(mystack.size() && mystack.top()< num)
        	{
        		table[mystack.top()]=num;
        		mystack.pop();
        	}
        	mystack.push(num);
        }
        vector<int> ret;

        for(auto & num:findNums)
        {
        	if(table.count(num))
        		ret.push_back(table[num]);
        	else
        		ret.push_back(-1);
        }
        return ret;
    }
};