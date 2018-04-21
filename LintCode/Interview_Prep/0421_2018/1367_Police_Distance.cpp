class Solution {
public:
    /**
     * @param matrix : the martix
     * @return: the distance of grid to the police
     */
    vector<vector<int>> policeDistance(vector<vector<int>> &matrix ) {
        // Write your code here
        vector<vector<int>> ret(matrix.size(),vector<int>(matrix[0].size(),INT_MAX));

        for(int i=0;i<matrix.size();i++)
        {
        	for(int j=0;j<matrix[i].size();j++ )
        	{
        		if(matrix[i][j]==1)
        			bfs(i,j,ret,matrix);
        		else if(matrix[i][j]==-1)
        		    ret[i][j]=-1;
        	}
        }
        return ret;
    }

    void bfs(int i,int j, vector<vector<int>> &ret,vector<vector<int>> &matrix)
    {
    	queue<pair<int,int>> q;
    	q.emplace(i,j);
    	int level=0;
    	vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};

    	while(!q.empty())
    	{
    		int t=q.size();
    		for(int i=0;i<t;i++)
    		{
    			int x=q.front().first;
    			int y=q.front().second;
    			q.pop();
    			if(level<ret[x][y])
    			{
    				ret[x][y]=level;
    				for(auto & d:dir)
    				{
    					int new_x=x+d[0];
    					int new_y=y+d[1];
    					if(new_x>=0 && new_x<matrix.size() && new_y>=0 && new_y<matrix[0].size() && matrix[new_x][new_y]==0)
    						q.emplace(new_x,new_y);
    				}
    			}
    		}
    		level++;
    	}
    }
};