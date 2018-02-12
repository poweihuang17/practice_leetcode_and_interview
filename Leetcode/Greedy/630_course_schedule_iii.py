import heapq
class Solution(object):
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
        
        courses.sort(key=lambda(t, end): end)

        max_heap=[]
        now=0

        for course in courses:
        	now+=course[0]
        	heapq.heappush(max_heap, -course[0])
        	if now>course[1]:
        		now+=heapq.heappop(max_heap)

        return len(max_heap)

s=Solution()
print s.scheduleCourse([[5,5],[4,6],[2,6]])