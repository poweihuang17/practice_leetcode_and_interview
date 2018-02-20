class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        table=[0]*(len(nums))
        table[0]=nums[0] 

        for i in range(1,len(nums)):
        	table[i]=max(table[i-1]+nums[i],nums[i])


        #print table
        return max(table)

s=Solution()
print s.maxSubArray([-2,1,-3,4,-1,2,1,-5,4])