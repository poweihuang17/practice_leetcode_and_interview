class Solution(object):
    def findMinArrowShots(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        if not points:
        	return 0

        points.sort()

        result=1
        current_range=points[0][1]

        
        for i in xrange(1,len(points)):
        	if points[i][0]<=current_range:
        		current_range=min(points[i][1], current_range)

        	else:
        		result+=1
        		current_range=points[i][1]
        return result

s=Solution()
print s.findMinArrowShots([[1,2],[2,3],[3,4],[4,5]])
