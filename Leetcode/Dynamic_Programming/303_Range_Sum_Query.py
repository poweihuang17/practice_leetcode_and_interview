class NumArray(object):

    # Need to do deep copy?
    def __init__(self, nums):
        """
        :type nums: List[int]
        """
        if not nums:
            self.nums=[]
            return 
            
        self.nums=[0]*len(nums)
        self.nums[0]=nums[0]
        for i in range(1,len(nums)):
            self.nums[i]=nums[i]+self.nums[i-1]

        

    def sumRange(self, i, j):
        """
        :type i: int
        :type j: int
        :rtype: int
        """
        if len(self.nums)==0:
            return 0

        return self.nums[j]-self.nums[i-1] if i-1>=0 else self.nums[j]

print NumArray([-2,0,3,-5,2,-1]).sumRange(0,2)