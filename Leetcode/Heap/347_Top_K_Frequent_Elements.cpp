class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    	unordered_map<int,int> table;
        for(auto & num:nums)
        {
        	table[num]++;
        }

        priority_queue< pair<int,int>,  vector< pair<int,int> > , greater<pair<int,int>>  > myqueue;
        for( auto & kv :table)
        	{
        		myqueue.push( make_pair(kv.second, kv.first) );
        		if(myqueue.size()>k)
        			myqueue.pop();
        	}
        vector<int> ans;
        while(!myqueue.empty())
        {
        	ans.push_back(myqueue.top().second);
            myqueue.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};