class Solution {
public:
    /**
     * @param start: The start points set
     * @param end: The end points set
     * @return: Return if the graph is cyclic
     */
    bool isCyclicGraph(vector<int> &start, vector<int> &end) {
        // Write your code here
        unordered_map<int,vector<int>> edge;
        unordered_map<int,int> visited;
        for(int i=0;i<start.size();i++)
            {
                edge[start[i]].push_back(end[i]);
                visited[start[i]]=0;
                visited[end[i]]=0;
            }

        for(auto & kv:edge)
        {
            int node=kv.first;
            if(visited[node]==0 && dfs(edge,visited,node))
                return true;

        }
        return false;
    }

    bool dfs( unordered_map<int,vector<int>> & edge,unordered_map<int,int> & visited, int node )
    {
        visited[node]=1;
        for(auto & next:edge[node])
        {
            if(visited[next]==1)
                return true;
            else if(visited[next]==2)
                continue;
            
            if(dfs(edge,visited,next))
                return true;
        }
        visited[node]=2;
        return false;
    }
};