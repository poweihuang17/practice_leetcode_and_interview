class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        unordered_map<char, vector<int> > table;
        unordered_map<string,bool> memory;

        for(int i=0;i<S.size();i++)
        	table[S[i]].push_back(i);

        int count=0;

        for(int i=0;i<words.size();i++)
        {
        	if(memory.count(words[i]))
        		{
        			count+=memory[words[i]];
        			continue;
        		}
        	count++;
            int prev=-1;
        	for(auto & c:words[i])
        	{
        		if(table.count(c))
        		{
        			auto it=lower_bound(table[c].begin(),table[c].end(),prev+1);
        			if(it==table[c].end()) { memory[words[i]]=false;count--;break;}
        			prev=*it;
        		}
        		else
        			{count--;break;}
        	}
        }
        return count;
    }
};