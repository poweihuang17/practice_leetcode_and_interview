class Solution(object):
    def dfs(self,grid,x,y):
    	if not 0<=x<len(grid) or not 0<=y<len(grid[0]) or grid[x][y]=='0':
    		return
    	grid[x][y]='0'

    	self.dfs(grid,x+1,y)
    	self.dfs(grid,x-1,y)
    	self.dfs(grid,x,y-1)
    	self.dfs(grid,x,y+1)

    def numIslands(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: int
        """
        count=0
        for i in range(len(grid)):
        	for j in range(len(grid[0])):
        		if grid[i][j]=='1':
        			count+=1
        			self.dfs(grid,i,j)
        return count

        


print Solution().numIslands([["1","1","1","1","0"],["1","1","0","1","0"],["1","1","0","0","0"],["0","0","0","0","0"]])

