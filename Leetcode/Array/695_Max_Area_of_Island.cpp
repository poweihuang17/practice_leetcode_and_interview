class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
       if(grid.size()==0 || grid[0].size()==0) return 0;
       max_count=0;
       for(int i=0;i<grid.size();i++)
       {
       	for(int j=0;j<grid[0].size();j++)
       	{
       		dfs(grid,i,j);
       	}
       }

       return max_count; 
    }

    int dfs(vector<vector<int>>& grid, int i ,int j)
    {
    	if(grid[i][j]==1)
    	{
    		grid[i][j]=0;
    		int count=1;
    		if(j>=1 && grid[i][j-1]==1)
    			count+=dfs(grid,i,j-1);
    		if(j<(grid[0].size()-1) && grid[i][j+1]==1)
    			count+=dfs(grid,i,j+1);
    		if(i>=1 && grid[i-1][j]==1)
    			count+=dfs(grid,i-1,j);
    		if(i<(grid.size()-1) && grid[i+1][j]==1)
    			count+=dfs(grid,i+1,j);
    		max_count=max(count,max_count);
    		return count;
    	}
    	else
    		return 0;
    }

private:
	int max_count;
};