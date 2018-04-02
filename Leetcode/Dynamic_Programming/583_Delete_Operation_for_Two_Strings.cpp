class Solution {
public:
    int minDistance(string word1, string word2) {
        vector< vector<int> > table( word1.size()+1, vector<int>(word2.size()+1,0));
        for(int i=word1.size()-1;i>=0;i--)
        	table[i][word2.size()]=table[i+1][word2.size()]+1;
        for(int i=word2.size()-1;i>=0;i--)
        	table[word1.size()][i]=table[word1.size()][i+1]+1;

        for(int i=word1.size()-1;i>=0;i--)
        	for(int j=word2.size()-1;j>=0;j--)
        	{
        		if(word1[i]==word2[j])
        			table[i][j]=table[i+1][j+1];
        		else
        			table[i][j]=min(table[i+1][j],table[i][j+1])+1;
        	}
        return table[0][0];
    }
};