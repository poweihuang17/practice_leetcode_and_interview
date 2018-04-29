class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(N,vector<vector<double>>(N,vector<double>(K+1,0)));
        vector<vector<int>> dir={{2,1},{2,-1},{1,2},{1,-2},{-1,-2},{-1,2},{-2,1},{-2,-1}};
        dp[r][c][0]=1;
        for(int i=0;i<K;i++)
        {
            for(int j=0;j<N;j++)
            {
                for(int t=0;t<N;t++)
                {
                    if(dp[j][t][i]==0)
                        continue;
                    
                    for(auto &d:dir)
                    {
                        int new_r=j+d[0];
                        int new_c=t+d[1];
                        if(new_r<N && new_r>=0 && new_c>=0 && new_c<N)
                        {
                            //cout<<"XXXX";
                            dp[new_r][new_c][i+1]+=0.125*dp[j][t][i];
                        }
                    }
                }
            }
            /*
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    cout<<dp[i][j][i+1]<<" ";
                }
                cout<<endl;
            } 
            */
        }
        
        double sum=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                //cout<<dp[i][j][K]<<" ";
                sum+=dp[i][j][K];
            }
            //cout<<endl;
        }
        return sum;
    }
};