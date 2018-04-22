class Solution {
public:

	void build(vector<string> & words)
	{
		for(auto & word:words)
		{
			prefix_table[""].push_back(word);
			string pre="";
			for(int i=0;i<word.size();i++)
			{
				pre+=word[i];
				prefix_table[pre].push_back(word);
			}
		}
	}

	bool checkprefix(int l, const string & w)
	{
		for(int k=l+1;k<maxlen;k++)
			{
				string pre;
				for(int i=0;i<l;i++)
				{
					pre+=squares[i][k];
				}
				pre+=w[k];
				if(prefix_table[pre].size()==0)
					return false;
			}
		return true;
	}

	void dfs(int l)
	{
		if(l==maxlen)
		{
			ret.push_back(squares);
			return ;
		}
		string pre="";
		for(int i=0;i<l;i++)
		{
			pre+=squares[i][l];
		}
		vector<string> & w=prefix_table[pre];
		for(int i=0;i<w.size();i++)
		{
			if(!checkprefix(l,w[i]))
				continue;
			squares.push_back(w[i]);
			dfs(l+1);
			squares.pop_back();
		}

	}

    vector<vector<string>> wordSquares(vector<string>& words) {
        if(words.size()==0) return {};
        maxlen=words[0].size();
        //build prefix table
        build(words);
        //dfs
        dfs(0);
        //
        return ret;
    }

private:
	unordered_map<string,vector<string>> prefix_table;
	vector<string> squares;
	vector<vector<string>> ret;
    int maxlen;

};