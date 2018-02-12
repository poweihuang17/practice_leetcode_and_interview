class Interval(object):
     def __init__(self, s=0, e=0):
         self.start = s
         self.end = e

class Solution(object):
    def employeeFreeTime(self, schedule):
        """
        :type schedule: List[List[Interval]]
        :rtype: List[Interval]
        """
        pool=[]
        
        for personal_schedule in schedule:
        	#print personal_schedule
        	for s in personal_schedule:
        		
        		pool.append(s)
        #print pool
        pool.sort(key=lambda s:(s.start,s.end))

        max_end=pool[0].start
        result=[]

        for s  in pool:
        	if s.start<=max_end:
        		max_end=max(max_end,s.end)
        	
        	else:
        		
        		result.append((max_end,s.start))
        		max_end=s.end
        
        return result
s=Solution()
print s.employeeFreeTime([     [Interval(1,3),Interval(6,7)]     ,[Interval(2,4)],   [Interval(2,5),Interval(9,12)]])
print s.employeeFreeTime([		[Interval(1,2),Interval(5,6)]	, 	[Interval(1,3)] , [Interval(4,10)] ])





