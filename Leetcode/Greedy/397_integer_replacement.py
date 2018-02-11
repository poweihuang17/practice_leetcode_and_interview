class Solution(object):
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n<4:
        	return [0,0,1,2][n]

        elif (n%2)==0:
        	return 1+self.integerReplacement(n/2)
        else:
        	return 1+min(self.integerReplacement(n+1),self.integerReplacement(n-1))