class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        visited=[[False for j in range(len(board[0]))] for i in range(len(board))]
        return any([self.exist_point(board,word,visited,i,j,0) for j in range(len(board[0])) for i in range(len(board))])

    def exist_point(self,board,word,visited,i,j,k):
    	#print (i,j,k)
    	visited[i][j]=True
    	if board[i][j]==word[k]:
    		if k==len(word)-1:
    			return True
    		else:		
    			if i<len(board)-1 and not visited[i+1][j]:
    				status=self.exist_point(board,word,visited,i+1,j,k+1)
    				if status:
    					
    					return True		
    			if i>0 and not visited[i-1][j]:
    				status=self.exist_point(board,word,visited,i-1,j,k+1)
    				if status:
    				    
    					return True
    			if j<len(board[0])-1 and not visited[i][j+1]:
    				status=self.exist_point(board,word,visited,i,j+1,k+1)
    				
    				if status:
    					
    					return True 
    			if j>0 and not visited[i][j-1]:
    				status=self.exist_point(board,word,visited,i,j-1,k+1)
    				
    				if status:

    					return True

    			visited[i][j]=False
    			return False
    			
    	else:
    		visited[i][j]=False
    		return False
s=[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]
for i in range(len(s)):
	print s[i]
print Solution().exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCCED")
print Solution().exist([["a","a"]],"aaa")
print Solution().exist([["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]],"ABCB")    	