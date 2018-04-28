class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        auto compare=[](const pair<int,int> & a, const pair<int,int> & b)
        {
        	return a.first<b.first || (a.first==b.first && a.second>b.second);
        };
        
        auto compare2=[](const pair<int,int> & a, const pair<int,int> & b)
        {
        	return a.first<b.first && a.second<b.second;
        };

        sort(envelopes.begin(),envelopes.end(),compare);
        
        auto m=envelopes.begin();
        
       	for(int i=0;i<envelopes.size();i++)
       	{
       		auto it=lower_bound(envelopes.begin(),m,envelopes[i],compare2);
       		*it=envelopes[i];
       		if(it==m)
       			m++;
       	}
       	return m-envelopes.begin();
    }
};