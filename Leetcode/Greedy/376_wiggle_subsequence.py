class Solution(object):
    def wiggleMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        
        if nums:
            if len(nums)<=1:
                return len(nums)
        else:
            return 0
        
        up=None
        transition=1
        
        for i in xrange(1,len(nums)):
            if nums[i-1]<nums[i] and (up==None or up==False):
                transition+=1
                up=True
                
            elif nums[i-1]>nums[i] and (up==None or up==True):
                transition+=1
                up=False
        
        return transition

s=Solution()
print s.wiggleMaxLength([1,7,4,9,2,5])
print s.wiggleMaxLength([1,17,5,10,13,15,10,5,16,8])
print s.wiggleMaxLength([1,2,3,4,5,6,7,8,9])
print s.wiggleMaxLength([0,0])