class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        max_area, i ,j =0,0,  len(height)-1
        
        while i<j:
            max_area=max(max_area, min(height[i],height[j]) * (j-i) )
            
            if height[i]>height[j]:
                j-=1
            else:
                i+=1
        
        return max_area