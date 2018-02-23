class Solution(object):
	def countArrangement(self, N):
		"""
		:type N: int
		:rtype: int
		"""
		return self.placement(N,N,[False for i in range(26)])

	def placement(self,N,placed,occupied_placed): 	
		if placed==(N+1):
			return 1
		count=0
		for j in reversed(range(1,N+1)):
			if not occupied_placed[j-1] and (placed%j==0 or j%placed==0):
				occupied_placed[j-1]=True
				
				if placed-1==(0):
					count+=1
				else:
					count+=self.placement(N,placed-1,occupied_placed)

				occupied_placed[j-1]=False
				

		return count

print Solution().countArrangement(2)
print Solution().countArrangement(3)
