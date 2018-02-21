class Solution(object):
    def maximalSquare(self, matrix):
        """
        :type matrix: List[List[str]]
        :rtype: int
        """
        if not matrix:
        	return 0
        for i in range(len(matrix)):
        	for j in range(len(matrix[0])):
        		matrix[i][j]=int(matrix[i][j])

        for i in range(1,len(matrix)):
        	for j in range(1,len(matrix[0])):
        		matrix[i][j]=min(int(matrix[i-1][j-1]),int(matrix[i-1][j]),int(matrix[i][j-1]))+1 if int(matrix[i][j]) else 0

        
        
        return max( [ max(table) for table in matrix ])**2

print Solution().maximalSquare([["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]])