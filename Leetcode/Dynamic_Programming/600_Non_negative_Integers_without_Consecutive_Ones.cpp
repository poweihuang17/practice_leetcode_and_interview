class Solution {
public:
    int findIntegers(int num) {
        vector<int> f(32,0);
        f[0]=1;
        f[1]=2;
        for(int i=2;i<31;i++)
        {
        	f[i]=f[i-1]+f[i-2];
        }
        int k=31;
        int ret=0;
        int pre=0;

        while(k>=0)
        {
        	if(num&(1<<k))
        	{
        		ret+=f[k];
        		if(pre) return ret;
        		pre=1;
        	}
        	else pre=0;

        	--k;
        }
        return ret+1;
    }
};