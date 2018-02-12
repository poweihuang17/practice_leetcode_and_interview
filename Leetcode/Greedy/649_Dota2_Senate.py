import collections

class Solution(object):
    def predictPartyVictory(self, senate):
        """
        :type senate: str
        :rtype: str
        """
        n=len(senate)
        radiant_dequeue, dire_dequeue=collections.deque(), collections.deque()

        for i,s in enumerate(senate):
        	if s=='R':
        		radiant_dequeue.append(i)
        	else:
        		dire_dequeue.append(i)
        

        while radiant_dequeue and dire_dequeue:
        	r,d=radiant_dequeue.popleft(), dire_dequeue.popleft()
        	if r<d:
        		radiant_dequeue.append(r+n)
        	else:
        		dire_dequeue.append(d+n)


        return  "Radiant" if radiant_dequeue else "Dire"

s=Solution()
print s.predictPartyVictory("RD")
print s.predictPartyVictory("RDD")