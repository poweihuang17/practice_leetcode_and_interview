class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& A) {
        sort(A.begin(),A.end());
        vector<long> table(A.size(),1);
        long count=0;
        for(int i=0;i<A.size();i++)
        {
            long p=A[i];
            for(int j=0;j<i;j++)
            {
                //cout<<i<<" "<<j<<endl;
                
                
                long t=A[i]/A[j];
                if(t<A[j]) break;
                
                auto it=find(A.begin(),A.begin()+i,t);
                if( (p%A[j])==0 && it!=(A.begin()+i) )
                {
                    if(t==A[j])
                        table[i]+=(table[j]*table[j]);
                    else
                        table[i]+=(2*table[it-A.begin()]*table[j]);
                }
            }
            //cout<<table[i]<<endl;
            count+=table[i];
        }
        return count% long( pow(10.0, 9.0) + 7);
    }
};