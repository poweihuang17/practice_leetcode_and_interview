class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        top=0
        for i in range(len(height)):
            if height[i]> height[top]:
                top=i
        result=0
        
        second_top=0
        for i in range(top):
            if height[second_top]< height[i]:
                second_top=i
            result+= height[ second_top ]-height[i]
        
        second_top=len(height)-1
        for i in reversed(range(top+1,len(height))):
            if height[second_top]<height[i]:
                second_top=i
            result+= height[second_top]-height[i]
        return result