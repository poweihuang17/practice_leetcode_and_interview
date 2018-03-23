class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s=s.strip(' ')
        s=s.split(' ')
        
        r=[]
        
        for e in s:
            if e!='':
                r.append(e)
        return ' '.join(list(reversed(r)))

print Solution().reverseWords("   a   b ")