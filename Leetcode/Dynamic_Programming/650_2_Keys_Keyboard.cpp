class Solution {
public:
    int minSteps(int n) {
        vector<int> table(n+1,0);
        for(int i=2;i<=n;i++)
        	{
                table[i]=i;
        		for(int j=i-1;j>=2;j--)
        			{
        				if(i%j==0) table[i]=min(table[i] , (i/j) + table[j] ) ;
        			}
        	}
        return table[n];
    }
};