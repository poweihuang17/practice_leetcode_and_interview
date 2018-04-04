class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> table;
        for(auto & c:p)
        	table[c]++;
        int count=table.size();

        int begin=0, end=0;
        vector<int> ret;

        while(end<s.size())
        {
        	if(table.count(s[end]))
        	{
        		table[s[end]]--;
        		if(table[s[end]]==0) count--;
        	}

        	end++;

        	while(count==0)
        	{
        		if(table.count(s[begin]))
        		{
        			if(table[s[begin]]==0) count++;
        			table[s[begin]]++;
        		}
        		if(end-begin==p.size())
        			ret.push_back(begin);
        		begin++;
        	}
        }
        return ret;
    }
};