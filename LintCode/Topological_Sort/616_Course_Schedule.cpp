class Solution {
public:
    /*
     * @param numCourses: a total of n courses
     * @param prerequisites: a list of prerequisite pairs
     * @return: the course order
     */
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        // write your code here
        unordered_map<int,vector<int>> graph;
        stack<int> mystack;
        for(auto & pre:prerequisites)
        {
        	graph[pre.second].push_back(pre.first);
        }
        vector<int> visited(numCourses,0);
        for (int i=0;i<numCourses;i++)
        	if(visited[i]==0 && tsort(graph,visited,i,mystack)) return {};
    	vector<int> ret;
    	while(mystack.size())
    	{
    		ret.push_back(mystack.top());
    		mystack.pop();
    	}
    	return ret;
    }

    bool tsort( unordered_map<int,vector<int>> & graph, vector<int> & visited, int node,stack<int> & mystack)
    {
    	visited[node]=1;
    	for(auto & next: graph[node])
    	{
    		if(visited[next]==0 && tsort(graph,visited,next,mystack))
    			    return true;
    		else if(visited[next]==1)
    		    return true;
    	}
    	visited[node]=2;
    	mystack.push(node);
    	return false;
    }

};