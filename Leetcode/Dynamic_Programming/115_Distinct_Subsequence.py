class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
       	table=[[0]*(len(s)+1) for i in range(len(t)+1)]
       	for i in range(1,len(t)+1):
       		table[i][0]=0
       	for i in range(len(s)+1):
       		table[0][i]=1

       	for i in range(1,len(t)+1):
       		for j in range(1,len(s)+1):
       			if s[j-1]!=t[i-1]:
       				table[i][j]=table[i][j-1]
       			else:
       				table[i][j]=table[i-1][j-1]+table[i][j-1]
       	'''
       	for i in range(len(t)+1):
       		print table[i]
       	'''
       	return table[len(t)][len(s)]

print Solution().numDistinct("rabbbit", "rabbit")
print Solution().numDistinct("rarbrc","r")