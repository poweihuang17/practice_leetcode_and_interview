import collections
import heapq

class Solution(object):
    def reorganizeString(self, S):
        """
        :type S: str
        :rtype: str
        """

        
        counter=collections.Counter(S)
        ans='#'

        while counter:
        	stop=True
        	for c, count in counter.most_common():
        		if c !=ans[-1]:
        			stop=False
        			ans+=c
        			counter[c]-=1
        			if counter[c]==0:
        				del counter[c]
        			break
        		else:
        			continue
        	if stop:
        		return ''
        return ans[1:]

s=Solution()
print s.reorganizeString("aab")
print s.reorganizeString("aaab")
print s.reorganizeString("acefgbdifelgh")
        	
