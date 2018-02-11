# Question: What's ascending stack?

class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        
        remaining=collections.defaultdict(int)
        
        for c in s:
            remaining[c]+=1
        
        in_stack, stack=set(), []
        
        for c in s:
            if c not in in_stack:
                while stack and stack[-1]>c and remaining[stack[-1]]>0:
                    in_stack.remove(stack.pop())
            
                stack+=c
                in_stack.add(c)
            remaining[c]-=1
        
        return ''.join(stack)