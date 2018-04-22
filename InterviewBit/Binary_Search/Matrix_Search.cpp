int Solution::searchMatrix(vector<vector<int> > &A, int B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    int i=0,j=A.size()*A[0].size()-1;
    while(i<j)
        {
            int mid=i+(j-i)/2;
            if(A[mid/A[0].size()][mid%A[0].size()]<B)
                i=mid+1;
            else if(A[mid/A[0].size()][mid%A[0].size()]>B)
                j=mid;
            else
                return 1;
        }
    return A[i/A[0].size()][i%A[0].size()]==B;
}
