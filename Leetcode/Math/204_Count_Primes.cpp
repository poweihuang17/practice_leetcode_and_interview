class Solution {
public:
    int countPrimes(int n) {
        if(n<2) return 0;
        
        vector<bool> notprime(n,false);
        int count=0;
        for(int i=2;i<n;i++)
        {
            if(notprime[i]==false)
            {
                count++;
                for(int j=2;i*j<n;j++)
                    notprime[i*j]=true;
            }
        }
        return count;
    }
};