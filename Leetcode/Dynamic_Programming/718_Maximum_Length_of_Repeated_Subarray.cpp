class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> table(A.size()+1, vector<int>(B.size()+1,0));
        
        int max_value=0;
        for(int i=1;i<A.size()+1;i++)
        {
        	for(int j=1;j<B.size()+1;j++)
        	{
        		if(A[i-1]==B[j-1])
        		{
        			table[i][j]=table[i-1][j-1]+1;
        			max_value=max(max_value,table[i][j]);
        		}
        		else
        			table[i][j]=0;
        	}
        }
        return max_value;
    }
};