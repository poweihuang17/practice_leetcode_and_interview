class Solution(object):
	def numWays(self, n, k):
		"""
		:type n: int
		:type k: int
		:rtype: int
		"""
		if n<=0 or k<=0:
			return 0
		if n==1:
			return k
		elif n==2:
			return k*k

		table=[(0,0)]*n
		table[0]=(k,k)
		table[1]=(k,k*(k-1))

		for i in range(2,n):
			table[i]=(table[i-1][1], table[i-1][1]*(k-1)+table[i-1][0]*(k-1))
		#print table
		return table[n-1][0]+table[n-1][1]

print Solution().numWays(3,2)