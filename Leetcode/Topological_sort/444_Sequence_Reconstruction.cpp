#include <unordered_set>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int>>& seqs) {
        
        int n=org.size();
        vector< unordered_set<int> > edges(n+1, unordered_set<int>());
        vector<int> degrees(n+1,0);

        bool empty=true;
        for(vector<int> seq:seqs)
        {
        	if(seq.empty()) {continue;}

        	empty=false;

        	if(seq[0] <1 || seq[0] > n ) {return false;}
        	for(int i=1;i<seq.size();i++)
        	{
        		if(seq[i]<1 || seq[i]>n) {return false;}
        		if(edges[seq[i-1]].count(seq[i])==0)
        		{
        			edges[seq[i-1]].insert(seq[i]);
        			degrees[seq[i]]++;
        		}
        	}
        }

        if(empty) {return false;}
        queue<int> myq;
        for(int i=1;i<=n;i++)
        {
        	
        	if(degrees[i]==0) myq.push(i);
        }

        int idx=0;
        while(!myq.empty())
        {
        	
        	if(myq.size()>1) {return false;}
        	int k=myq.front();
        	myq.pop();
        	if(k!=org[idx++]) {return false;}
        	for(int i:edges[k])
        	{
        		if(--degrees[i]==0) myq.push(i);
        	}
        }
        
        return idx==n;
    }
};

int main()
{
	Solution s=Solution();
	vector<int> v={1};
	vector<vector<int>> u={ {1},{1},{1}};
	cout<<s.sequenceReconstruction(v,u)<<'\n';
}