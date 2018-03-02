#include <unordered_map>
#include <string>
#include <iostream>
#include <queue>
#include <utility>
#include <stack>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> result;
        if(n==1)
        {
        	result.push_back(0);
        	return result;
        }

        unordered_map<int, unordered_set<int> > adj;

        for(auto & edge :edges)
        {
        	adj[edge.first].insert(edge.second);
        	adj[edge.second].insert(edge.first);
        }
        vector <int> leaves;

        for( auto & kv:adj)
        {
        	if(kv.second.size()==1)
        		leaves.push_back(kv.first);
        }
        while(n>2)
        {
        	n-=leaves.size();
        	vector <int> nextleaves;
        	for (auto & leave : leaves)
        	{
        		int nextNode=*(adj[leave].begin());
        		adj[leave].erase(nextNode);
        		adj[nextNode].erase(leave);

        		if (adj[nextNode].size()==1)
        			nextleaves.push_back(nextNode);
        	}
        	leaves=nextleaves;
        }
        return leaves;
    }
};