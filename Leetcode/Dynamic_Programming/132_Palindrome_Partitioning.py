class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        cut=[0]*(len(s)+1)
        for i in range(len(s)+1):
        	cut[i]=i-1

        n=len(s)
        
        for i in range(len(s)):

        	# Odd palindrome
        	j=0
        	while i-j >=0 and i+j<n and s[i-j]==s[i+j]:
        		#print (i,j,False)
        		#print cut
        		cut[i+j+1]=min(cut[i+j+1],cut[i-j]+1)
        		#print cut
        		j+=1

        	# Even palindrome
        
        	j=0
        	while i-j>=0 and i+j+1<n and s[i-j]==s[i+j+1]:
        		#print (i,j,True)
        		cut[i+j+2]=min(cut[i+j+2],cut[i-j]+1)
        		j+=1

        return cut[len(s)]

print Solution().minCut("aab")
print Solution().minCut("aabbc")

