class Solution(object):
    def countCornerRectangles(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        # Brute forced
        total=0
        for i in range(len(grid[0])):
        	for j in range(i+1,len(grid[0])):
        		count=0
        		for k in range(len(grid)):
        			if grid[k][i]==1 and grid[k][j]==1:
        				count+=1
        		total+=count*(count-1)/2
        return total
s=Solution()
print s.countCornerRectangles( [[1, 0, 0, 1, 0], [0, 0, 1, 0, 1],  [0, 0, 0, 1, 0],  [1, 0, 1, 0, 1]])
print s.countCornerRectangles( [[1, 1, 1],  [1, 1, 1],  [1, 1, 1]])
print s.countCornerRectangles( [[1, 1, 1, 1]])