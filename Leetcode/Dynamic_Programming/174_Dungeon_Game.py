class Solution(object):
    def calculateMinimumHP(self, dungeon):
        """
        :type dungeon: List[List[int]]
        :rtype: int
        """

        dungeon[-1][-1]=max(1-dungeon[-1][-1],1)

        for i in reversed(range(0,len(dungeon[0])-1)):
        	dungeon[-1][i]=max(dungeon[-1][i+1]-dungeon[-1][i],1)

        for i in reversed(range(0,len(dungeon)-1)):
        	dungeon[i][-1]=max(dungeon[i+1][-1]-dungeon[i][-1],1)

        for i in reversed(range(0, len(dungeon)-1)):
        	for j in reversed(range(0,len(dungeon[0])-1)):
        		direction1=max(1, dungeon[i+1][j]-dungeon[i][j])
        		direction2=max(1,dungeon[i][j+1]-dungeon[i][j])
        		dungeon[i][j]=min(direction2,direction1)

        #print dungeon
        return dungeon[0][0]

dungeon = [[ -2,  -3,  3], \
               [ -5, -10,  1], \
               [ 10,  30, -5]]
print Solution().calculateMinimumHP(dungeon)
    
dungeon = [[ -200]]
print Solution().calculateMinimumHP(dungeon)

dungeon = [[0, -3]]
print Solution().calculateMinimumHP(dungeon)
