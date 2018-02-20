class Solution(object):
    def numTrees(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<=0:
        	return 0

        table=[0]*(n+1)
        table[0]=1
        if n==1:
        	return 1

        table[1]=1
        for i in range(2,n+1):
        	for k in range(i):
        		table[i]+=table[k]*table[i-1-k]

        return table[n]

print Solution().numTrees(3)