import string
class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        if not s1 or not s2:
        	return False
        
        if s1==s2:
        	return True
       

        counter={}
        for s in string.ascii_lowercase:
        	counter[s]=0
        
        for s in s1:
        	counter[s]+=1
        for s in s2:
        	counter[s]-=1

        for s in counter:
        	if counter[s]!=0:
        		print "counter"
        		return False


        table=[[[False]*len(s1) for i in range(len(s2))] for i in range(len(s1)+1)]
        for i in range(len(s1)):
        	for j in range(len(s2)):
        		table[1][i][j]=(s1[i]==s2[j])


        for k in range(2,len(s1)+1):
        	for i in range(len(s1)-k+1):
        		for j in range(len(s2)-k+1):
        			for l in range(1,k):
        				if (table[l][i][j] and table[k-l][i+l][j+l]) or (table[l][i][j+k-l] and table[k-l][i+l][j]):
	
        					table[k][i][j]=True
        					break

        return table[k][0][0]

print Solution().isScramble("rgtae", "great")
