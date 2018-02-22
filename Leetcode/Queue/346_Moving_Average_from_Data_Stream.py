import collections
class MovingAverage(object):

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.array=collections.deque()
        self.size=size
        self.count=0
        self.mysum=0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        self.array.append(val)
        self.count+=1
        self.mysum+=val
        
        if self.count>self.size:
            self.mysum-=self.array.popleft()
            self.count-=1


        return self.mysum/float(self.count)
        


# Your MovingAverage object will be instantiated and called as such:
# obj = MovingAverage(size)
# param_1 = obj.next(val)