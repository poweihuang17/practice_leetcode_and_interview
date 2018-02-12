class Solution(object):
    def intersectionSizeTwo(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        intervals.sort()
        filtered_intervals=[]
        #print intervals
        for interval in intervals:
        	while filtered_intervals and filtered_intervals[-1][1]>=interval[1]:
        		filtered_intervals.pop()
        	filtered_intervals.append(interval)
        	


        result=0
        p1,p2=float('-inf'),float('-inf')

        #print filtered_intervals

        for interval in filtered_intervals:
        	condition1=interval[0]<=p1<=interval[1]
        	condition2=interval[0]<=p2<=interval[1]

        	if condition1 and condition2:
        		continue

        	elif condition1:
        		p2=interval[1]
        		result+=1
        	
        	elif condition2:
        		p1=interval[1]
        		result+=1

        	else:
        		p2=interval[1]
        		p1=p2-1
        		result+=2
        return result

s=Solution()
print s.intersectionSizeTwo([[1, 3], [1, 4], [2, 5], [3, 5]])
print s.intersectionSizeTwo([[1, 2], [2, 3], [2, 4], [4, 5]])
print s.intersectionSizeTwo([[1,24],[10,16],[14,25],[0,18],[16,17]])



