class NumMatrix(object):

    def __init__(self, matrix):
        """
        :type matrix: List[List[int]]
        """
        if not matrix or not matrix[0]:
            self.matrix_sum=[]
            return 

        self.matrix_sum=[[matrix[i][j] for j in range(len(matrix[0]))] for i in range(len(matrix))]

        for i in range(1,len(matrix[0])):
            self.matrix_sum[0][i]+=self.matrix_sum[0][i-1]

        for i in range(1,len(matrix)):
            self.matrix_sum[i][0]+=self.matrix_sum[i-1][0]

        for j in range(1,len(matrix[0])):
            for i in range(1,len(matrix)):
                self.matrix_sum[i][j]=self.matrix_sum[i][j]+self.matrix_sum[i-1][j]+self.matrix_sum[i][j-1]-self.matrix_sum[i-1][j-1]
        '''
        for i in range(len(matrix)):
            print self.matrix_sum[i] 
        '''

    def sumRegion(self, row1, col1, row2, col2):
        """
        :type row1: int
        :type col1: int
        :type row2: int
        :type col2: int
        :rtype: int
        """
        if not self.matrix_sum:
            return 0

        if col1-1>=0 and row1-1>=0:
            #print "1"
            return self.matrix_sum[row2][col2]+self.matrix_sum[row1-1][col1-1]-self.matrix_sum[row1-1][col2]-self.matrix_sum[row2][col1-1]
        elif col1-1<0 and row1-1<0:
            #print "4"
            return self.matrix_sum[row2][col2]

        elif col1-1>=0:
            #print "2"
            return self.matrix_sum[row2][col2]-self.matrix_sum[row2][col1-1]
        elif row1-1>=0:
            #print "3"
            return self.matrix_sum[row2][col2]-self.matrix_sum[row1-1][col2]
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
print NumMatrix([[-4,-5]]).sumRegion(0,0,0,0)
print NumMatrix([[-4,-5]]).sumRegion(0,0,0,1)
print NumMatrix([[-4,-5]]).sumRegion(0,1,0,1)