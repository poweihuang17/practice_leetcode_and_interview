class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> n(10002,0);
        for(auto & num:nums)
            n[num]+=1;
        vector<int> dp(10002,0);
        dp[1]=n[1];
        dp[2]=n[2]*2;
        for(int i=2;i<10001;i++)
            dp[i]=max(dp[i-2]+i*n[i],dp[i-1]);
        return max(dp[10000],dp[9999]);
    }
};