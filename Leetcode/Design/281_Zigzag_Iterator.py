class ZigzagIterator(object):

    def __init__(self, v1, v2):
        """
        Initialize your data structure here.
        :type v1: List[int]
        :type v2: List[int]
        """
        self.v1=v1
        self.v2=v2
        self.pointer1=0
        self.pointer2=0
        if v1:
            self.who=1
        else:
            self.who=2
        

    def next(self):
        """
        :rtype: int
        """
        if self.who==1:
            self.pointer1+=1
            if self.pointer2<len(self.v2):
                self.who=2
            return self.v1[self.pointer1-1]
        else:
            self.pointer2+=1
            
            if self.pointer1<len(self.v1):
                self.who=1
            return self.v2[self.pointer2-1]
        

    def hasNext(self):
        """
        :rtype: bool
        """
        if self.who==1 and self.pointer1<len(self.v1):
            return True
        elif self.who==2 and self.pointer2<len(self.v2):
            return True
        else:
            return False
        

# Your ZigzagIterator object will be instantiated and called as such:
# i, v = ZigzagIterator(v1, v2), []
# while i.hasNext(): v.append(i.next())