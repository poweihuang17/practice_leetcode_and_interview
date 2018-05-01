#include <string>
#include <vector>
#include <iostream>
using namespace std;

void build(string & p, vector<int> next)
{
	int i=1,j=0;
	next[0]=0;
	while(i<p.size())
	{
		if(p[i]==p[j])
		{
			next[i]=j+1;
			i++;
			j++;
		}
		else if(j!=0)
			j=next[j-1];	
		else
			i++;
	}
	return ;
}

int kmp(string & p, string &t)
{
	vector<int> next(p.size(),0);
	build(p,next);
	int i=0,j=0;
	while(i<t.size())
	{
		if(t[i]==p[j])
		{
			if(j==p.size()-1)
				return i-j;
			i++;
			j++;
		}
		else if(j!=0)
		{
			j=next[j-1];
		}
		else
			i++;
	}
	return -1;

}

int main()
{
	string x="ababacb";
	string y="abfdleigjtababacbdf";
	cout<<kmp(x,y);
	return 0;
}