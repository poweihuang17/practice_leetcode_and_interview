class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        m=len(grid)
        n=len(grid[0])

        if m==0 or n==0:
        	return 0
        
        table=[[0]* n for i in range(m)]

        table[0][0]=grid[0][0]

        init_sum=grid[0][0]

        for i in range(1,n):
            table[0][i]=init_sum+grid[0][i]
            init_sum=table[0][i]

        init_sum=grid[0][0]
        for i in range(1,m):
            table[i][0]=init_sum+grid[i][0]
            init_sum=table[i][0]

        for i in range(1,m):
        	for j in range(1,n):
        		direction1=table[i-1][j] 
        		direction2=table[i][j-1] 
        		#print direction1
        		#print direction2
        		table[i][j]=min(direction1,direction2)+grid[i][j]
        '''
        for i in range(m):
        	print table[i]
		'''
        return table[m-1][n-1]

s=Solution()
print s.minPathSum([[1,3,1],[1,5,1],[4,2,1]])