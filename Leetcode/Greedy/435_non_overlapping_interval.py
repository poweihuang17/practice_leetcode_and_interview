# Definition for an interval.
class Interval(object):
     def __init__(self, s=0, e=0):
         self.start = s
         self.end = e

class Solution(object):
    def eraseOverlapIntervals(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: int
        """

        def overlapped(interval1, interval2):
        	if interval1.end>interval2.start and interval1.start<interval2.end:
        		return True
        	else: 
        		return False


        intervals.sort(key=lambda interval: interval.start)
        result, prev=0,0

        for i in xrange(1, len(intervals)):
        	if overlapped(intervals[i],intervals[prev]):
        		prev= prev if intervals[i].end > intervals[prev].end else i
        		result+=1

        		#print (prev, i)

        	else:
        		prev=i

        return result

s=Solution()
print s.eraseOverlapIntervals([Interval(1,100),Interval(11,22),Interval(1,11),Interval(2,12)])



