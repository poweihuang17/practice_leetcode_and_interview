class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        table=[ (nums[i],nums[i]) for i in range(len(nums))]

        table[0]=(nums[0],nums[0])

        for i in range(1, len(nums)):
        	table[i]=(max(table[i][0],table[i-1][0]*nums[i], table[i-1][1]*nums[i]), min(table[i][1], table[i-1][0]*nums[i],table[i-1][1]*nums[i]))
        
        #print table

        return  max(table[i][0] for i in range(len(nums)))

print Solution().maxProduct([2,3,-2,4])
print Solution().maxProduct([2,3,-2,-4])