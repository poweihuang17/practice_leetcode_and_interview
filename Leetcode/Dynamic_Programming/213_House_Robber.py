class Solution(object):
	def normalrob(self, nums):
		if not nums:
			return 0
		elif len(nums)==1:
			return nums[0]
		elif len(nums)==2:
			return max(nums) 
		nums[1]=max(nums[0],nums[1])
		for i in range(2,len(nums)):
			nums[i]=max(nums[i-1],nums[i-2]+nums[i])
		return nums[-1]
	
	def rob(self, nums):
		if not nums:
			return 0

		return max(self.normalrob(nums[1:]), self.normalrob(nums[:-1]),nums[0],nums[-1])