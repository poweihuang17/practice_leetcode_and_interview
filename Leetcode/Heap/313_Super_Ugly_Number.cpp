class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        if(n==1) return 1;
        priority_queue<long,vector<long>,greater<long>> q;
        q.push(1);

        for(int i=1;i<n;i++)
        {
        	long p=q.top();
            while(!q.empty() && p==q.top())
                q.pop();
            for(auto & prime:primes)
            	q.push(prime*p);
        }
        return q.top();
    }
};