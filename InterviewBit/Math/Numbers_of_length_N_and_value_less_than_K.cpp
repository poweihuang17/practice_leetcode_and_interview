#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
//Solution1 : Backtracking
/*
bool helper(vector<int> & A,int sum,int B,int C,int & count, int & test)
{
	if(B<0)
		return true;
	else if (sum>=C)
		return false;

	if(B==0 && sum>= test) count++;
	for(int i=0;i<A.size();i++)
	{
		bool x=helper(A,sum*10+A[i],B-1,C,count,test);
		if(!x) break;
	}
	return true;
}

int Solution::solve(vector<int> &A, int B, int C) {
	sort(A.begin(),A.end());
	int sum=0;
	int test=B==1? 0: pow(10,B-1);
    int count=0;
	for(int i=0;i<A.size();i++)
	{
		bool x=helper(A,sum*10+A[i],B-1,C,count,test);
		if(!x) break;
	}
	return count;
}
*/

//Solution2:DP


int Solution::solve(vector<int> & A, int B, int C)
{

if (A.empty()) return 0;
	int lc=0;
	int d=C;
	vector<int> prefix;
	while(d>0)
	{
        prefix.push_back(d%10);
		d=d/10;
		lc++;
	}
	
	if(lc>B)
	{
	    if(B==1)
	        return A.size();
	    else
		    return pow((double)A.size(),(double)B-1.0)*(A.size()-(A[0]==0));
	}
	else if(lc<B)
	{
		return 0;
	}
	else
	{
	    
	    if(prefix.size()==1)
	        return upper_bound(A.begin(),A.end(),prefix[0])-A.begin();
	    int count1=0;
	    int count2=1;
	    for(int i=0;i<prefix.size();i++)
	        {
    		int k=prefix[prefix.size()-1-i];
    		auto it=lower_bound(A.begin(),A.end(),k);
    		int m=it-A.begin();
    		//cout<<m;

    		//cout<<m<<'\n';

    		   
    		if(i==0)
    		    {
    		        count1=A[0]==0?m-1:m;//Smaller prefix
    		    }
    		else
    		    {
    		        count1=count1*A.size()+count2*m;
    		    }
    		if(count2==1 && find(A.begin(),A.end(),k)==A.end())
    		    count2=0;
    		//cout<<count2<<'\n';
    		//cout<<count1<<'\n';
	        }
	    return count1;
	}
}



int main()
{
	vector<int> A{0, 2, 3, 4, 5, 7, 8, 9};
	int B=5;
	int C=86587;
	solve(A,B,C);
}



