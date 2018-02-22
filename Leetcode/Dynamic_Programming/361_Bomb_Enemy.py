class Solution(object):
	def maxKilledEnemies(self, grid):
		"""
		:type grid: List[List[str]]
		:rtype: int
		"""
		if not grid or not grid[0]:
			return 0

		#Left,Right,Up,Down
		kill=[[ [0,0,0,0] for j in range(len(grid[0])+2)] for i in range(len(grid)+2)]

		#Right/Down scan
		
		for i in range(1,len(grid)+1):
			for j in range(1,len(grid[0])+1):
				if grid[i-1][j-1]=='0':
					kill[i][j][0]=kill[i][j-1][0]
					kill[i][j][3]=kill[i-1][j][3]
				elif grid[i-1][j-1]=='E':
					kill[i][j][0]=kill[i][j-1][0]+1
					kill[i][j][3]=kill[i-1][j][3]+1
				else:
					kill[i][j][0]=0
					kill[i][j][3]=0
					
		#Left/Up scan
	
		for i in reversed(range(1,len(grid)+1)):
			for j in reversed(range(1,len(grid[0])+1)):
				if grid[i-1][j-1]=='0':
					kill[i][j][1]=kill[i][j+1][1]
					kill[i][j][2]=kill[i+1][j][2]
				elif grid[i-1][j-1]=='E':
					kill[i][j][1]=kill[i][j+1][1]+1
					kill[i][j][2]=kill[i+1][j][2]+1
				else:
					kill[i][j][1]=0
					kill[i][j][2]=0

		for i in range(1,len(kill)-1):
			for j in range(1,len(kill[0])-1):
				kill[i][j]=sum(kill[i][j])-(sum(kill[i][j]) if grid[i-1][j-1]=='E' else 0)

		return  max([max([ kill[i][j] for j in range(1,len(kill[0])-1)]) for i in range(1,len(kill)-1)])
print Solution().maxKilledEnemies([["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]])

print Solution().maxKilledEnemies([["0","0","0","0","0","0","0","0","0","0"],["E","E","E","E","E","E","E","E","E","E"],["W","W","W","W","W","W","W","W","W","W"]])