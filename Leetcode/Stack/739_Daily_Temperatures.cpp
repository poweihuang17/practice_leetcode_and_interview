class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> descending;
        vector<int> res(temperatures.size(),0);

        for(int i=0;i<temperatures.size();i++)
        {
        	while(!descending.empty() && temperatures[descending.top()] < temperatures[i])
        	{
        		int t=descending.top();
        		descending.pop();
        		res[t]=i-t;
        	}
        	descending.push(i);
        }
        return res;
    }
};