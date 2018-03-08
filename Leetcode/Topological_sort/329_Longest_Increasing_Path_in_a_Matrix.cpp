#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
    	if(matrix.size()==0) return 0;
    	//Adjacency list for digraph
    	vector<vector<int>> graph(matrix.size()*matrix[0].size(), vector<int>());
    	vector<int> length(matrix.size()*matrix[0].size(),1);
    	vector<int> start(matrix.size()*matrix[0].size(),1);
    	//0:not visited, 1: visiting, 2: visited;
    	vector<int> visited(matrix.size()*matrix[0].size(),0);
    	int width=matrix[0].size();
    	for(int i=0;i<matrix.size();i++)
    	{
    		for (int j=0;j<matrix[0].size();j++)
    		{
    			if(i>0 && matrix[i][j]<matrix[i-1][j])
    				graph[i*width+j].push_back((i-1)*width+j);
    			if(i<matrix.size()-1 && matrix[i][j]< matrix[i+1][j])
    				graph[i*width+j].push_back((i+1)*width+j);
    			if(j<matrix[0].size()-1 && matrix[i][j]<matrix[i][j+1])
  					graph[i*width+j].push_back(i*width+j+1);
    			if (j>0 && matrix[i][j]<matrix[i][j-1])
    				graph[i*width+j].push_back(i*width+j-1);
    		}
    	}

    	for(int i=0;i<matrix.size()*matrix[0].size();i++)
    		{
    			if(visited[i]==0) dfs(graph, length, i , visited);
    			/*
    			for(int i=0;i<matrix.size()*matrix[0].size();i++)
    				{
    				cout<<length[i]<<' ';
    				if(i%matrix[0].size()==matrix[0].size()-1) cout<<'\n';
    				}
    			cout<<'\n';
    			*/
    		}
    	/*
    	for(int i=0;i<matrix.size()*matrix[0].size();i++)
    		cout<<length[i]<<'\n';
    	*/

    	return *max_element(length.begin(),length.end());
    }



private:

    int dfs(vector <vector<int> > & graph, vector<int> & length , int node, vector<int> & visited)
	{

		int connected_length=0;
		for(int i=0;i<graph[node].size();i++)
		{
			if(visited[graph[node][i]]==2)
				connected_length=connected_length<length[ graph[node][i]]+1?  length[ graph[node][i]]+1: connected_length;
		}

		visited[node]=1;

		int dfs_length=length[node];
		int temp_dfs=dfs_length; 
		for(int i=0;i<graph[node].size();i++)
		{
			if(visited[graph[node][i]]==0)
				dfs_length=max(temp_dfs+dfs(graph,length, graph[node][i], visited),dfs_length);
		}

		length[node]=max(max(connected_length,length[node]),dfs_length);

		visited[node]=2;
		return length[node];
	}

	inline int index(int i,int j,int width)
	{
		return i*width+j;
	}
};

int main()
{
	Solution s=Solution();
	vector<vector<int>> matrix={{1,2}};
	std::cout<<s.longestIncreasingPath(matrix)<<'\n';

	cout<<'\n';
	vector<vector<int>> matrix2={{9,9,4},{6,6,8},{2,1,1}};
	std::cout<<s.longestIncreasingPath(matrix2)<<'\n';

	cout<<'\n';
	vector<vector<int>> matrix3={{3,4,5},{3,2,6},{2,2,1}};
	std::cout<<s.longestIncreasingPath(matrix3)<<'\n';

	cout<<'\n';
	vector<vector<int>> matrix4={{1,2},{2,3}};
	std::cout<<s.longestIncreasingPath(matrix4)<<'\n';
}