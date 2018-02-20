class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        table=[0] * n

        if n<=2:
        	return n
        
        table[0]=1
        table[1]=2

        for i in range(2,n):
        	table[i]=table[i-1]+table[i-2]

        return table[n-1]