int Solution::uniquePaths(int A, int B) {
    vector<vector<int>> table(A,vector<int>(B,0));
    
    for(int i=0;i<A;i++)
        table[i][0]=1;
    for(int i=0;i<B;i++)
        table[0][i]=1;
    
    for(int i=1;i<A;i++)
    {
        for(int j=1;j<B;j++)
            table[i][j]=table[i-1][j]+table[i][j-1];
    }
    return table[A-1][B-1];
}
