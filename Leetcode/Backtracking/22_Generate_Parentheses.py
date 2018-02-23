class Solution(object):
	def addParenthesis(self, res, string,left,right):
		
		if left==0 and right==0:
			res.append(string)
			return
		
		if (right>0):
			self.addParenthesis(res,string+")",left,right-1)
		if (left > 0):
			self.addParenthesis(res,string+"(",left-1,right+1)

	def generateParenthesis(self, n):
		if n<0:
			return []
		result=[]
		self.addParenthesis(result,"",n,0)
		return result

print Solution().generateParenthesis(3)