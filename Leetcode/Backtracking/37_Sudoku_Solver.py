class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: void Do not return anything, modify board in-place instead.
        """
        row_rule=[ [False for i in range(9)] for j in range(9)]
        column_rule=[ [False for i in range(9)] for j in range(9)]
        block_rule=[[ [False for i in range(9)] for j in range(3)] for k in range(3)]
        count=0

        for i in range(9):
        	for j in range(9):
        		if board[i][j]!='.':
        			row_rule[i][int(board[i][j])-1]=True
        			column_rule[j][int(board[i][j])-1]=True
        			block_rule[i/3][j/3][int(board[i][j])-1]=True
        			count+=1

        self.solveSudoku_by_rule(board,row_rule,column_rule,block_rule,0,0, count)


    def solveSudoku_by_rule(self,board,row_rule,column_rule,block_rule,row,column,count):
		#print  (row,column)
		#print  count
		if board[row][column]=='.':
			for k in range(9):
				#print  row_rule[row]
				#print  column_rule[column]

				if row_rule[row][k]==False and column_rule[column][k]==False and block_rule[row/3][column/3][k]==False:
					#print  row_rule[row]
					#print  column_rule[column]
					#print  "k:%d" % k
					column_rule[column][k]=True
					row_rule[row][k]=True
					block_rule[row/3][column/3][k]=True
					#print  row_rule[row]
					#print  column_rule[column]
					board[row][column]=str(k+1)
					count+=1
					if count!=81:
						#print  "Put:%d" %k
						new_column=(column+1)%9
						new_row=row+1 if column==8 else row
						status=self.solveSudoku_by_rule(board,row_rule,column_rule,block_rule,new_row,new_column,count)
						if status:
							return True
					else:
						return True

					column_rule[column][k]=False
					row_rule[row][k]=False
					block_rule[row/3][column/3][k]=False
					board[row][column]='.'
					count-=1

			#for i in range(len(board)):
			#	print  board[i]
			#print  ""
			return False
		else:
			if count!=80:
				new_column=(column+1)%9
				new_row=row+1 if column==8 else row
				return self.solveSudoku_by_rule(board,row_rule,column_rule,block_rule,new_row,new_column,count)
			else:
				return True

y=([[".",".","9","7","4","8",".",".","."],["7",".",".",".",".",".",".",".","."],[".","2",".","1",".","9",".",".","."],[".",".","7",".",".",".","2","4","."],[".","6","4",".","1",".","5","9","."],[".","9","8",".",".",".","3",".","."],[".",".",".","8",".","3",".","2","."],[".",".",".",".",".",".",".",".","6"],[".",".",".","2","7","5","9",".","."]])
for i in range(len(y)):
	print  y[i]
print  ""

print Solution().solveSudoku(y)
for i in range(len(y)):
	print  y[i]