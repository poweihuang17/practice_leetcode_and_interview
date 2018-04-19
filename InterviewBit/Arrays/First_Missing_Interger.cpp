#include<vector>
#include <iostream>
using namespace std;


int Solution::firstMissingPositive(vector<int> &A) {
    for(int i=0;i<A.size();i++)
    {
        if(A[i]>=1 && A[i]<=A.size())
            {
                if(A[i]!=A[A[i]-1])
                    {
                        swap(A[i],A[A[i]-1]);
                        i--;
                    }
                    
            }
    }
    for(int i=0;i<A.size();i++)
    {
        if(A[i]!=i+1)
            return i+1;
    }
    
	return A.size()+1;
}






int main()
{
	vector<int> A{1};
	cout<<firstMissingPositive(A);
}