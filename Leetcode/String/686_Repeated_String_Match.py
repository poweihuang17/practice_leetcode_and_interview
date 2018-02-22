class Solution(object):
    def repeatedStringMatch(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: int
        """

        if len(A)>len(B):
        	if B in A:
        		return 1
        	elif B in A+A:
        		return 2
        	else:
        		return -1
        else:
        	C=A
        	while len(C)<len(B):
        		 C+=A
        	
        	if B in C:
        		return len(C)/len(A)
        		
        	elif B in C+A:
        		return len(C)/len(A)+1
        	else:
        		return -1

print Solution().repeatedStringMatch("abcd","cdabcdab")

