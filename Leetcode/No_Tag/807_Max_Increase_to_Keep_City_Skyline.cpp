class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowcount(grid.size(),0);
        vector<int> colcount(grid[0].size(),0);
        for(int i=0;i<grid.size();i++)
        	for(int j=0;j<grid[0].size();j++)
        	{
        		rowcount[i]=max(rowcount[i],grid[i][j]);
        		colcount[j]=max(colcount[j],grid[i][j]);
        	}
        int count=0;
        for(int i=0;i<grid.size();i++)
        	for(int j=0;j<grid[0].size();j++)
        		count+=(min(rowcount[i],colcount[j])-grid[i][j]);
        return count;
    }
};