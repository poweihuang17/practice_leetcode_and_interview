class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size()<=2) return 0;
        vector<int> table(A.size(),0);
        if( (A[0]+A[2])==(A[1]*2) ) table[2]=1;
        for(int i=3;i<A.size();i++)
        {
        	if ( (A[i-1]*2)==(A[i]+A[i-2]))
        	{
        		table[i]=2*table[i-1]-table[i-2]+1;
        	}
        	else
        	{
        		table[i]=table[i-1];
        	}
        }
        return table[A.size()-1];
    }
};