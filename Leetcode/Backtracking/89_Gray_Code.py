class Solution(object):
	def grayCode(self,n):
		l=self.grayCode_String(n)
		for i in range(len(l)):
			l[i]=int(l[i],2)
		return l

	
	def grayCode_String(self, n):
		"""
		:type n: int
		:rtype: List[int]
		"""
		if n==0:
			return ['0']
		elif n==1:
			return ['0','1']
		r=self.grayCode_String(n-1)
		length=len(r)
		result=['' for i in range(2*length)]

		for i in range(length):
			#print (r[i],result[i])
			result[i]='0'+r[i]
			result[-i-1]='1'+r[i]

		return result

print Solution().grayCode(3)
print Solution().grayCode(0)



