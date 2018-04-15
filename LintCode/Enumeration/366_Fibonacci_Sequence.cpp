class Solution {
public:
    /**
     * @param n: an integer
     * @return: an ineger f(n)
     */
    int fibonacci(int n) {
        // write your code here
        int k=max(n,3);
        vector<int> table(k);
        table[0]=0;
        table[1]=1;
        for(int i=2;i<k;i++)
        {
        	table[i]=table[i-1]+table[i-2];
        }
        return table[n-1];
    }
};