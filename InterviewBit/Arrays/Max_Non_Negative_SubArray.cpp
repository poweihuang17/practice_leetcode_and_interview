vector<int> Solution::maxset(vector<int> &A) {
    vector<int> ret;
    long long sum=0;
    vector<int> cur;
    long long sum_cur=0;
    A.push_back(-1);
    for(auto & a:A)
    {
        if(a>=0) 
            {
            sum_cur+=a;
            cur.push_back(a);
            }
        else
            {
            if(sum<sum_cur || (sum==sum_cur && cur.size()>ret.size()))
                {
                    sum=sum_cur;
                    ret=cur;
                    sum_cur=0;
                    cur.clear();
                }
            else
                {
                    sum_cur=0;
                    cur.clear();
                }
            }
    }
    A.pop_back();
    return ret;
}
