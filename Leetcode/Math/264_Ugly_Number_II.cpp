class Solution {
public:
    int nthUglyNumber(int n) {
        if(n==1) return 1;
        priority_queue<long,vector<long>,greater<long>> q;
        q.push(1);

        for(int i=1;i<n;i++)
        {
        	long p=q.top();
            while(!q.empty() && p==q.top())
                q.pop();
        	q.push(p*2);
        	q.push(p*3);
        	q.push(p*5);
        }
        return q.top();
    }
};