class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        next_range=0
        current_range=0
        step=0
        
        for index, item in enumerate(nums):
            if index> current_range:
                current_range=next_range
                step+=1
            
            next_range=max(next_range, index+item)

        return  step