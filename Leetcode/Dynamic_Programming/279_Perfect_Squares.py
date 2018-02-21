class Solution(object):
    def numSquares(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<=0:
        	return 0

        table=[float('inf')]*(n+1)
        table[0]=0

        for i in range(1,n+1):

        	j=1
        	temp=i-j**2
        	while temp>=0:
        		table[i]=min(table[temp]+1, table[i])
        		j+=1
        		temp=i-j**2
        
        #print table

        return table[n]

print Solution().numSquares(12)
