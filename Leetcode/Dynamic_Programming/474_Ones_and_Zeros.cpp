class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        dp[0][0]=0;
        for(int k=0;k<strs.size();k++)
        {
        	int count1=0;
        	int count2=0;
        	for(auto &s:strs[k])
        		if(s=='0') count1++;
        		else count2++;
        	for(int i=m;i>=count1;i--)
        	{
        		for(int j=n;j>=count2;j--)
        		{
        			dp[i][j]=max(dp[i-count1][j-count2]+1,dp[i][j]);
        		}
        	}
        }
        return dp[m][n];
    }
};