class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector< vector<int> > table( s1.size()+1, vector<int>(s2.size()+1,0));
        for(int i=s1.size()-1;i>=0;i--)
        	table[i][s2.size()]=table[i+1][s2.size()]+s1[i];
        for(int i=s2.size()-1;i>=0;i--)
        	table[s1.size()][i]=table[s1.size()][i+1]+s2[i];

        for(int i=s1.size()-1;i>=0;i--)
        	for(int j=s2.size()-1;j>=0;j--)
        	{
        		if(s1[i]==s2[j])
        			table[i][j]=table[i+1][j+1];
        		else
        			table[i][j]=min(table[i+1][j]+s1[i],table[i][j+1]+s2[j]);
        	}
        return table[0][0];
    }
};