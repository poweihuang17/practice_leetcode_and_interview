class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(),0);
        vector<int> ret;
        
        for(int i=0;i<graph.size();i++)
        {
            int node=i; 
            if(visited[node]==0 && !dfs(graph,visited,node))
            {
                    ret.push_back(i);
            }
            else if(visited[node]==2)
            {
                ret.push_back(i);
            }
        }
        
        return ret;
    }
    
    bool dfs( vector<vector<int>>& edge,vector<int> & visited, int node)
    {
        visited[node]=1;
        bool safe=false;
        for(auto & next:edge[node])
        {
            if(visited[next]==1)
            {
                visited[node]=3;
                return true;
            }
            else if(visited[next]==3)
            {
                visited[node]=3;
                return true;
            }
            else if(visited[next]==2)
                continue;
            
            if(dfs(edge,visited,next))
                {
                visited[node]=3;
                return true;
                }
        }
        visited[node]=2;
        return false;
    }
        
    
};