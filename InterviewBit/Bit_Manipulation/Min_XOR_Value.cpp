int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(),A.end());
    int ret=INT_MAX;
    for(int i=1;i<A.size();i++)
    {
        ret=min(ret,A[i]^A[i-1]);
    }
    return ret;
}
