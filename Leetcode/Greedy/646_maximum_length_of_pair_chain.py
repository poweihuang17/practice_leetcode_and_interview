class Solution(object):

    def overlapped(self,interval1, interval2):
    	if interval1[1]>=interval2[0] and interval1[0]<=interval2[1]:
    		return True
    	else: 
    		return False

    def findLongestChain(self, pairs):
        """
        :type pairs: List[List[int]]
        :rtype: int
        """

        pairs.sort(key=lambda interval: interval[0])
        result, prev=0,0

        for i in xrange(1, len(pairs)):
        	if self.overlapped(pairs[i],pairs[prev]):
        		prev= prev if pairs[i][1] > pairs[prev][1] else i
        		result+=1

        		

        	else:
        		prev=i

        return len(pairs)-result
s=Solution()
print s.findLongestChain([[1,2], [2,3], [3,4]])