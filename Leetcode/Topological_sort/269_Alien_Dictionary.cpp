//The key: Use iterator and count to avoid the type problem.
//Otherwise, we need to do a conversion from string to int.
class Solution {
public:
    string alienOrder(vector<string>& words) {
    	if(words.size()==1) return words[0];
    	unordered_map<char, unordered_set<char> > g;
    	for(int i=1;i<words.size();i++)
    	{
    		string t1=words[i-1];
    		string t2=words[i];

    		bool found=false;
    		for(int j=0;j<max(t1.length(),t2.length());j++)
    		{
    			if(j<t1.length() && g.count(t1[j])==0)
    				g.insert(make_pair(t1[j],unordered_set<char>()));
    			if(j<t2.length() && g.count(t2[j])==0)
    				g.insert(make_pair(t2[j],unordered_set<char>()));
    			if(j<t1.length() && j<t2.length() && t1[j]!=t2[j] && !found)
    			{
    				g[t1[j]].insert(t2[j]);
    				found=true;
    			}
    		}
    	}
    	return topsort(g);
    }

private:

	string topsort(unordered_map<char, unordered_set<char> >  & g)
	{
		unordered_set<char> visited;
		unordered_set<char> visiting;
		string order;

		for(auto iter=g.begin();iter!=g.end();iter++)
		{
			if(dfs(g, visited, visiting, order, iter->first)==false)
				return "";
		}
		reverse(order.begin(),order.end());
		return order;
	}

	bool dfs(unordered_map<char, unordered_set<char> >& g,unordered_set<char>& visited, unordered_set<char>& visiting, string& order, char n) 
	{
		if(visiting.count(n)) return false;
		if(visited.count(n)) return true;
		
		visiting.insert(n);
		for(auto iter=g[n].begin();iter!=g[n].end();iter++)
			if(dfs(g,visited, visiting, order,*iter)==false)
				return false;

		visiting.erase(visiting.find(n));
		visited.insert(n);
		order+=string(1,n);
		return true;
	}

};