class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """

        table=[[False]*(len(s)+1) for i in range(len(p)+1)]

        table[0][0]=True

        for i in range(1,len(s)+1):
        	table[0][i]=False

        for i in range(1,len(p)+1):
        	table[i][0]=i>1 and '*'==p[i-1] and table[i-2][0]

       	for i in range(1, len(p)+1):
       		for j in range(1,len(s)+1):
       			if s[j-1]==p[i-1]:
       				table[i][j]=table[i-1][j-1]
       			elif p[i-1]=='.':
       				table[i][j]=table[i-1][j-1]
       			elif p[i-1]=='*':
       				if p[i-2]=='.' or p[i-2]==s[j-1]:
       					table[i][j]=table[i][j-1] or table[i-2][j-1] or table[i-2][j]
       				elif p[i-2]!=s[j-1]:
       					table[i][j]=table[i-2][j]
       	'''
       	for i in range(len(p)+1):
       		print table[i]
		'''
       	return table[len(p)][len(s)]
s=Solution()
#print s.isMatch("aa","a")
#print s.isMatch("aa","aa")
#print s.isMatch("aaa","aa")
#print s.isMatch("aa", "a*")
print s.isMatch("aa", ".*")
print s.isMatch("ab", ".*")
#print s.isMatch("aab", "c*a*b")

#print s.isMatch("aaa","ab*ac*a")