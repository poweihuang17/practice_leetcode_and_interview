class Solution {
public:
    bool validWordSquare(vector<string>& words) {
    	if(words.empty()) return false;
        for(int i=0;i<words.size();i++)
        {
        	for(int j=0;j<words[i].size();j++)
        	{
        		if( i>=words[j].size() || j>=words.size() || words[i][j]!=words[j][i])
        			return false;
        	}
        }
        return true;
    }
};