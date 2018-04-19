#include <vector>
#include <set>
#include <math.h>
#include <iostream>
using namespace std;

vector<int> Solution::primesum(int A) {
	//set<int> prime;
	bool * t=new bool[A+1];
	for(int i=0;i<=A;i++)
	    t[i]=true;
	
	int m=sqrt((double)A);
	//cout<<m;
	for(int i=2;i<=A;i++)
	{
		if(t[i])
			{
				for(int j=i<<1;j<=A;j+=i)
				{
					t[j]=false;
				}
			}
	}
	
	for(int i=2;i<=A;i++)
	{
		if(i>A/2)
			break;
		if(t[i] && t[A-i])
			{
				delete [] t;
				return vector<int>{i,A-i};
			}
	}
	return vector<int>{0,A};
	
}


int main(){
	primesum(10);
}
