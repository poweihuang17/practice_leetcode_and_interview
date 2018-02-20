class Solution(object):
    def uniquePaths(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        if m==0 or n==0:
        	return 0
        
        table=[[1]* n for i in range(m)]

        for i in range(1,m):
        	for j in range(1,n):
        		table[i][j]=table[i-1][j]+table[i][j-1]

        for i in range(m):
        	print table[i]

        return table[m-1][n-1]

s=Solution()
print s.uniquePaths(3,7)
