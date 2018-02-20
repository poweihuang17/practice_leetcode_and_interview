class Solution(object):
    def uniquePathsWithObstacles(self, obstacleGrid):
        """
        :type obstacleGrid: List[List[int]]
        :rtype: int
        """
        m=len(obstacleGrid)
        n=len(obstacleGrid[0])

        if m==0 or n==0:
        	return 0
        
        table=[[1]* n for i in range(m)]

        blocked=False
        for i in range(n):
        	if obstacleGrid[0][i]:
        		blocked=True
        	table[0][i]=0 if blocked else 1

        blocked=False
        for i in range(m):
        	if obstacleGrid[i][0]:
        		blocked=True
        	table[i][0]=0 if blocked else 1

        for i in range(1,m):
        	for j in range(1,n):
        		direction1=table[i-1][j] 
        		direction2=table[i][j-1] 
        		#print direction1
        		#print direction2
        		table[i][j]=direction1 + direction2 if obstacleGrid[i][j]==0 else 0
        '''
        for i in range(m):
        	print table[i]
		'''
        return table[m-1][n-1]
s=Solution()
print s.uniquePathsWithObstacles([[0,0],[0,0]])
print s.uniquePathsWithObstacles([[0,0],[0,1]])