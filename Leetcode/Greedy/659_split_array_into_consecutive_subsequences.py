import collections

class Solution(object):
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        count=collections.Counter(nums)
        prev=-float('inf')
        count1,count2,count3=0,0,0

        for cur in nums :
        	if cur==prev:
        		continue
        	elif cur!= (prev+1):
        		if count1==0 and count2==0:
        			count1, count2, count3=count[cur],0,0
        			prev=cur
        			#print (count1,count2,count3)
        		else:
        			#print "Here"
        			return False

        	else: #cur==prev+1
        		if count[cur]>=(count1+count2):
        			count1,count2,count3=max(0, count[cur]-count2-count1-count3) , count1 , count2+min(count[cur]-count2-count1,count3)
        			prev=cur
        			#print (count1,count2,count3)
        		else:
        			#print "There"
        			return False
        return True if count1==0 and count2==0 else False

s=Solution()
print s.isPossible([1,2,3,3,4,5])
print s.isPossible([1,2,3,3,4,4,5,5])
print s.isPossible([1,2,3,4,4,5])
print s.isPossible([1])
print s.isPossible([1,2,3,3,4,4,5,5])

