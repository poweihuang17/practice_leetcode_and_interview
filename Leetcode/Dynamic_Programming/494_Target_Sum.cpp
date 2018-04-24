class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int dp[20][2001]={0};
        dp[0][nums[0]+1000]+=1;
        dp[0][-nums[0]+1000]+=1;
        for(int i=1;i<nums.size();i++)
        {
        	for(int j=0;j<2001;j++)
        	{
                if(j-nums[i]>=0)
        		    dp[i][j]+=dp[i-1][j-nums[i]];
                if(j+nums[i]<=2000)
        		    dp[i][j]+=dp[i-1][j+nums[i]];
        	}
        }
        if(S<=1000 && S>=-1000)
            return dp[nums.size()-1][S+1000];
        else
            return 0;
    }
};