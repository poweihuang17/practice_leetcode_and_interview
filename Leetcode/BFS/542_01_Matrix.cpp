class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    	
    	if(matrix.empty()) return matrix;
    	queue<pair<int,int>> myqueue;
    	int rows=matrix.size(), cols=matrix[0].size();

    	vector<vector<int> > result(rows, vector<int>(cols, 0));

    	vector<vector<int>> dirs={{-1,0},{0,1},{0,-1},{1,0}};

        for(int i=0;i<matrix.size();i++)
        {
        	for(int j=0;j<matrix[0].size();j++)
        	{
        		if(matrix[i][j]==0)
        			myqueue.push({i,j});
        		else
        			result[i][j]=-1;
        	}
        }

        while(!myqueue.empty())
        {
        	pair<int,int> p= myqueue.front();
        	int r=p.first;
        	int c=p.second;
        	myqueue.pop();

        	for(auto & dir : dirs)
        	{
        		int new_r=r+dir[0];
        		int new_c=c+dir[1];
        		if(new_r>=0 && new_r<rows && new_c<cols && new_c>=0 && result[new_r][new_c]==-1)
        		{
        			myqueue.push({new_r,new_c});
        			result[new_r][new_c]=result[r][c]+1;
        		}
        	}
        }
        return result;

    }

};