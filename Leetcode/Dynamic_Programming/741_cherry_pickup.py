class Solution(object):
    def cherryPickup(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """

        table=[[[0]*len(grid) for i in xrange(len(grid))] for i in xrange(len(grid))]


        for x1 in xrange(1,len(grid)):
        	for y1 in xrange(1,len(grid)):
        		for x2 in xrange(1,len(grid)):
        			if grid[x1][y1]==-1 or grid[x2][x1+y1-x2]==-1
        				table[x1][y1][x2]=0
        			else:
        				table[x1][y1][x2]=(x1!=x2)+1+max(table[x1-1][y1][x2-1],table[x1][y1-1][x2-1],table[x1][y1-1][x2],table[x1-1][y1][x2])






