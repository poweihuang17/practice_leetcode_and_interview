#include <vector>
#include <iostream>
using namespace std;

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
	vector< pair<int,bool> > endpoints;
	for(auto & a:arrive)
		endpoints.push_back({a,false});
	for(auto & b:depart)
		endpoints.push_back({b,true});
	
	auto compare=[](const pair<int,bool> a, const pair<int,bool> b)
	{
		if(a.first<b.first || (a.first==b.first && a.second==true))
			return true;
		else
			return false;
	};

	sort(endpoints.begin(),endpoints.end(),compare);

	int count=0;
	//cout<<endpoints.size()<<endl;
	for(auto & endpoint:endpoints)
	{
	    //cout<<endpoint.first<<' '<<endpoint.second<<endl;
		if(endpoint.second==false)
			{
				count++;
				if(count>K)
					return false;
			}
		else
		{
			count--;
		}
	}
	return true;
}



int main(){
	vector<int> arrive{1,2,3,4};
	vector<int> depart{10,2,6,14};
	int c=4;
	cout<<hotel(arrive,depart,c);
}

bool Solution::hotel(vector<int> &arrive, vector<int> &depart, int K) {
	sort(arrive.begin(),arrive.end());
	sort(depart.begin(),depart.end());
	int count=0;
	int i=0,j=0;

	while(i<arrive.size() && j<depart.size())
	{
		if(arrive[i]<depart[j])
			{
				count++;
				if(count>K) return false;
				i++;
			}
		else //if(arrive[i]>depart[j])
		{
			count--;
			j++;
		}
	}
	return true;
}

