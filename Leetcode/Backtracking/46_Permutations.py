class Solution(object):
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums)==0:
        	return [[]]

        
        return [ [n]+p for i, n in enumerate(nums) for p in self.permute(nums[:i]+nums[i+1:])]

print Solution().permute([1,2,3])