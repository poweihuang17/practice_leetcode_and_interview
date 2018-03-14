#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
    	if( graph.size()==0) return false;

        vector<int> party(graph.size(),0);
        bool result=true;
        for(int i=0;i<graph.size();i++)
        {
        	if(party[i]==0)
        	{
        		party[i]=1;
        		if(!dfs(graph,party,i)) result=false;
        	}	
        }

        return result;
    }

    bool dfs( vector<vector<int>> & graph, vector<int> & party, int node)
    {
    	
    	for(auto & neighbor : graph[node])
    	{
    		if(party[neighbor]==0)
    			{
    				party[neighbor]=-1*party[node];
    				if( dfs(graph,party,neighbor))  continue;
    				else
    					return false;
    			}
    		else if( party[node]==1 && party[neighbor]==-1)
    			continue;
    		else if (party[node]==-1 && party[neighbor]==1)
    			continue;
    		else
    		{
    			return false;
    		}
    	}
    	return true;
    }
};

int main()
{
	vector<vector<int>> graph{{1,3},{0,2},{1,3},{0,2}};
	vector<vector<int>> graph2{ {1,2,3}, {0,2}, {0,1,3}, {0,2}};
	Solution s =Solution();
	cout<<s.isBipartite(graph2);
}