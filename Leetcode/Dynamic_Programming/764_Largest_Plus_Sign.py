class Solution(object):
    def orderOfLargestPlusSign(self, N, mines):
        """
        :type N: int
        :type mines: List[List[int]]
        :rtype: int
        """

        grid=[[1]*N for i in range(N)]


        for mine in mines:
        	grid[mine[0]][mine[1]]=0

        for  i in range(N):
        	count=0
        	for j in range(N):
        		count=0 if grid[i][j]==0 else count+1
        		grid[i][j]=count

        	count=0
        	for j in reversed(range(N)):
        		count=0 if grid[i][j]==0 else count+1
        		grid[i][j]=min(grid[i][j],count)

        for j in range(N):
        	count=0
        	for i in range(N):
        		count=0 if grid[i][j]==0 else count+1
        		grid[i][j]=min(grid[i][j],count)

        	count=0
        	for i in reversed(range(N)):
        		count=0 if grid[i][j]==0 else count+1
        		grid[i][j]=min(grid[i][j],count)

        max_1=float('-inf')
        for i in range(N):
        	for j in range(N):
        		max_1=max(max_1, grid[i][j])

        return max_1
