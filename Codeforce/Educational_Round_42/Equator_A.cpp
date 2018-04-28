#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<long long> v;
	for(int i=0;i<n;i++)
		{
			long long temp;
			cin>>temp;
			v.push_back(temp);
		}
	long long x=0;
	long long s=accumulate(v.begin(),v.end(),x);
	//s/=2;
	long long sum=0;
	for(int i=0;i<v.size();i++)
	{
		sum+=v[i];
		if(2*sum>=s) {//cout<<i+1<<endl;
			cout<<i+1;return 0;}
	}
}	