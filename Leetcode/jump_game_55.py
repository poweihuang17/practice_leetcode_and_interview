
class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        max_index=0

        for i, num in enumerate(nums):
        	if i > max_index:
        		return False
        	else:
        		max_index= max(i+num, max_index)

        	if max_index >= len(nums)-1:
        		return True
        
        #print max_index

        return False

Solution=Solution()
print Solution.canJump([2,3,1,1,4])
print Solution.canJump([3,2,1,0,4])