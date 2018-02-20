class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """

        for i in reversed(xrange(len(triangle)-1)):
        	for j in xrange(len(triangle[i])):
        		triangle[i][j]+=min(triangle[i+1][j],triangle[i+1][j+1])

       	return triangle[0][0]

print Solution().minimumTotal([[2],[3,4],[6,5,7],[4,1,8,3]])
