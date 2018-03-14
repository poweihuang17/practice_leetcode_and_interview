class Solution {
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        
        if(matrix.empty()) return vector<pair<int, int>>();

        int row=matrix.size();
        int col=matrix[0].size();

        vector<vector<bool> > ocean1(row,vector<bool> (col, false));
        vector<vector<int>> dirs={{-1,0},{0,1},{0,-1},{1,0}};
        vector<vector<bool> > ocean2(row,vector<bool> (col, false));

        queue<pair<int,int>> queue_1;
        for(int i=0;i<col;i++)
        	queue_1.push({0,i});
        for(int i=1;i<row;i++)
        	queue_1.push({i,0});

        while(!queue_1.empty())
        {
        	pair<int,int> x=queue_1.front();
        	int r=x.first;
        	int c=x.second;
        	ocean1[r][c]=true;
        	queue_1.pop();

        	for(auto & dir : dirs)
        	{
        		int new_r=r+dir[0];
        		int new_c=c+dir[1];
        		if(new_r>=0 && new_r<row && new_c<col && new_c>=0 && ocean1[new_r][new_c]==false && matrix[r][c]<=matrix[new_r][new_c])
        		{
        			queue_1.push({new_r,new_c});
        		}
        	}
        }

        for(int i=0;i<col;i++)
        	queue_1.push({row-1,i});
        for(int i=0;i<row-1;i++)
        	queue_1.push({i,col-1});

        while(!queue_1.empty())
        {
        	pair<int,int> x=queue_1.front();
        	int r=x.first;
        	int c=x.second;
        	ocean2[r][c]=true;
        	queue_1.pop();

        	for(auto & dir : dirs)
        	{
        		int new_r=r+dir[0];
        		int new_c=c+dir[1];
        		if(new_r>=0 && new_r<row && new_c<col && new_c>=0 && ocean2[new_r][new_c]==false && matrix[r][c]<=matrix[new_r][new_c])
        		{
        			queue_1.push({new_r,new_c});
        		}
        	}
        }

        vector<pair<int, int>> result;

        for(int i=0;i<row;i++)
        {
        	for(int j=0;j<col;j++)
        	{
        		if(ocean2[i][j] && ocean1[i][j])
        			result.push_back({i,j});

        	}
        }
        return result;
    }
};