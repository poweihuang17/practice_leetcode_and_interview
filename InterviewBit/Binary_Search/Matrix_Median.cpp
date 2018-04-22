int count(vector<vector<int>> & A, int number,int & result)
{
    int ret=0;
    result=INT_MAX;
    for(auto & row:A)
    {
        auto it=upper_bound(row.begin(),row.end(),number);
        ret+=( it-row.begin());
        result=it==row.end()?result:min(result,*it);
    }
    return ret;
}


int Solution::findMedian(vector<vector<int> > &A) {
    
    int m=A.size();
    int n=A[0].size();
    int target=(m*n)/2;
    int i=1,j=INT_MAX;

    while(i<j)
    {
        int mid=i+(j-i)/2;
        int result;
        int k=count(A,mid,result);
        if(k==target)
            return result;
        else if(k>target)
            j=mid;
        else
            i=mid+1;
        
    }
    return i;
}
