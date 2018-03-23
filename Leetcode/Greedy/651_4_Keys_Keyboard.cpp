class Solution {
public:
    int maxA(int N) {
        vector<int> table(N+1, 0);
        for(int i=0;i<=N;i++)
        {
        	table[i]=i;
        	for(int j=1;j<=i-3;j++)
        		table[i]=max(table[i], (i-j-1)*table[j]);
        }
        return table[N];
    }
};