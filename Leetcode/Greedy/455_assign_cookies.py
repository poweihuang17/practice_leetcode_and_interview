class Solution(object):
    def findContentChildren(self, g, s):
        """
        :type g: List[int]
        :type s: List[int]
        :rtype: int
        """

        g.sort(key=lambda s: -s )
        s.sort(key=lambda s:-s)

        index=0
        result=0
        for g1 in g:
        	if index < len(s):
        		if g1 <= s[index]:
        			result+=1
        			index+=1
        		


        return result