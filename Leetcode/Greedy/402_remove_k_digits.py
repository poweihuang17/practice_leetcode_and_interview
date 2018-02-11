class Solution(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """

        def smallestArray(nums1,k):
        	stack=[]
        	remaining=len(nums1)
        	for s in nums1:
        		while stack and (remaining+len(stack))>k and stack[-1]>s:
        				stack.pop()
        		
        		if len(stack)<k:
        			stack+=s
        		remaining-=1

        		#print ''.join(stack)

        	return ''.join(stack)

        return smallestArray(num,len(num)-k).lstrip('0') or '0'

class Solution2(object):
    def removeKdigits(self, num, k):
        """
        :type num: str
        :type k: int
        :rtype: str
        """
        result = []
        for d in num:
            while k and result and result[-1] > d:
                result.pop()
                k -= 1
            result.append(d)
            print ''.join(result)

        return ''.join(result)

s=Solution()
print s.removeKdigits("10200",1)
