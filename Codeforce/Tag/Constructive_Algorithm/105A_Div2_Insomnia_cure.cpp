#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int k,l,m,n,d;
	cin>>k>>l>>m>>n>>d;
	vector<bool> c(d+1,true);
	int ret=0;
	for(int i=k;i<=d;i+=k)
		if(c[i])
			{
				ret++;
				c[i]=false;
			}
	
	for(int i=l;i<=d;i+=l)
		if(c[i])
		{
			ret++;
			c[i]=false;
		}
	for(int i=m;i<=d;i+=m)
		if(c[i])
		{
			ret++;
			c[i]=false;
		}
	for(int i=n;i<=d;i+=n)
		if(c[i])
		{
			ret++;
			c[i]=false;
		}
	cout<<ret;
	return 0;
}