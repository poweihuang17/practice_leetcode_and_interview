class Solution(object):
    def minPatches(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: int
        """
        patch, miss, i = 0, 1, 0

        while miss<=n:
        	if i<len(nums) and nums[i]<=miss:
        		miss=miss+nums[i]
        		i+=1
        	
        	else:
        		miss=miss+miss
        		patch+=1

        return patch

