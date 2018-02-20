class Solution(object):
    def isInterleave(self, s1, s2, s3):
        """
        :type s1: str
        :type s2: str
        :type s3: str
        :rtype: bool
        """
        if len(s1)+len(s2)!=len(s3):
        	return False

        match=[[False for i in xrange(len(s2)+1)] for j in xrange(len(s1)+1)]

        match[0][0]=True
        for i in range(1,len(s2)+1):
        	match[0][i]=match[0][i-1] and s3[i-1]==s2[i-1]

        for i in range(1,len(s1)+1):
        	match[i][0]=match[i-1][0] and s3[i-1]==s1[i-1]

        for i in range(1,len(s1)+1):
        	for j in range(1,len(s2)+1):
        		match[i][j]=(match[i-1][j] and s3[i+j-1]==s1[i-1]) or (match[i][j-1] and s3[i+j-1]==s2[j-1])

        return match[len(s1)][len(s2)]
print Solution().isInterleave("aabcc", "dbbca", "aadbbcbcac")
print Solution().isInterleave("aabcc", "dbbca","aadbbbaccc")