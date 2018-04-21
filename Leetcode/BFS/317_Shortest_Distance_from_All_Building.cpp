class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        // Write your code here
        int count=0;
        for(auto & row:grid)
            for(auto & item:row)
                count+=(item==1);
        
        vector<vector<vector<int>>> ret(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(count,0)));
        int index=0;
        for(int i=0;i<grid.size();i++)
        {
        	for(int j=0;j<grid[i].size();j++ )
        	{
        		if(grid[i][j]==1)
                    {
                        bfs(i,j,ret,grid,index);
                        index++;
                    }
        	}
        }

        int ret2=INT_MAX;
        for(int i=0;i<grid.size();i++)
        	for(int j=0;j<grid[0].size();j++)
        		if(grid[i][j]==0)
                {
                    bool test=true;
                    int count=0;
                    for(auto item:ret[i][j])
                    {
                        if(item==0) {test=false;break;}
                        count+=item;
                    }
                    if(test) ret2=min(ret2,count);
                    //cout<<i<<' '<<j<<' '<<ret2<<endl;
                    
                }
        
        return ret2==INT_MAX? -1:ret2;
    }

    void bfs(int i,int j, vector<vector<vector<int>>> &ret,vector<vector<int>> &grid,int index)
    {
    	queue<pair<int,int>> q;
    	q.emplace(i,j);
    	int level=0;
    	vector<vector<int>> dir{{0,1},{0,-1},{1,0},{-1,0}};
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
    	while(!q.empty())
    	{
    		int t=q.size();
    		for(int i=0;i<t;i++)
    		{
    			int x=q.front().first;
    			int y=q.front().second;
                visited[x][y]=1;
    			q.pop();
                //cout<<x<<' '<<y<<' '<<level<<endl;
				ret[x][y][index]+=level;
				for(auto & d:dir)
				{
					int new_x=x+d[0];
					int new_y=y+d[1];
					if(new_x>=0 && new_x<grid.size() && new_y>=0 && new_y<grid[0].size() && grid[new_x][new_y]==0 && visited[new_x][new_y]==0)
                        {
                            q.emplace(new_x,new_y);
                            visited[new_x][new_y]=1;
                        }
				}
    			
    		}
    		level++;
    	}
    }
};