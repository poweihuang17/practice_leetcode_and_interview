class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
        	return 0
        table=[0]*len(s)
        if '1'<=s[0]<='9':
        	table[0]=1
        if len(s)==1:
        	return table[0]

        if 10<=int(s[0:2])<=26:
        	table[1]+=1

        if '1'<=s[1]<='9':
        	table[1]+=(table[0])

        for i in range(2,len(s)):
        	direction1=table[i-1] if '1'<=s[i]<='9' else 0
        	direction2= table[i-2] if 10<=int(s[i-1:i+1])<=26 else 0
        	table[i]=direction1+direction2

        return table[len(s)-1] 

print Solution().numDecodings("01")  