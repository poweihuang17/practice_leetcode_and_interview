class Solution {
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int n = bottom.size();
        vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(7, false)));
        unordered_map<char,unordered_set<string>> m;

        for(string str:allowed)
        	m[str[2]].insert(str.substr(0,2));
        
        for(int i=0;i<n;i++)
        {
        	dp[n-1][i][bottom[i]-'A']=true;
        }
        for(int i=n-2;i>=0;i--)
        {
        	for(int j=0;j<=i;j++)
        	{
        		for(char ch='A';ch<='G';ch++)
        		{
        			if(!m.count(ch)) continue;
        			for(string str:m[ch])
        				if(dp[i+1][j][str[0]-'A'] && dp[i+1][j+1][str[1]-'A'])
        					dp[i][j][ch-'A']=true;
        		}
        	}
        }

        for(int i=0;i<7;i++)
        {
        	if(dp[0][0][i]) return true;
        }
        return false;
    }
};