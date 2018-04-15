class Rectangle:

    '''
     * Define a constructor which expects two parameters width and height here.
    '''
    # write your code here
    def __init__(self,height,width):
    	self.height=height if height>0 else 0
    	self.width=width if width>0 else 0
    '''
     * Define a public method `getArea` which can calculate the area of the
     * rectangle and return.
    '''
    # write your code here
    def getArea(self):
    	return self.width*self.height