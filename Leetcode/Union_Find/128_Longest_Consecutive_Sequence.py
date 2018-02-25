class Solution(object):
	def longestConsecutive(self, nums):
		"""
		:type nums: List[int]
		:rtype: int
		"""
		if not nums:
			return 0
		vtable={} # The maximum length starting from x
		htable={} # The other end of x

		for  i in nums:
			if i in vtable:
				continue

			vtable[i]=1
			htable[i]=i
			
			if i+1 in vtable:
				vtable[i]+=vtable[i+1]
				htable[i]=htable[i+1]
				htable[htable[i+1]]=i

			if i-1 in vtable:
				vtable[htable[i-1]]+=vtable[i]
				htable[htable[i]]=htable[i-1]
				if i+1 in vtable:
					htable[htable[i+1]]=htable[i-1]
					htable[htable[i-1]]=htable[i]
				else:
					htable[i]=htable[i-1]
					htable[htable[i-1]]=i
			
			#print vtable
			#print htable
			#print ''

		return max(vtable.values())

print Solution().longestConsecutive( [100, 4, 200, 1, 3, 2])
print Solution().longestConsecutive([1,3,5,2,4])
print Solution().longestConsecutive([3,4,5,1,2])
print Solution().longestConsecutive([3,5,2,4])
print Solution().longestConsecutive([-2,-3,-3,7,-3,0,5,0,-8,-4,-1,2])
print Solution().longestConsecutive([5,-7,-8,7,6,5,-8,9,4,4,2,0,-2,6,6,2,6,7,-5,5,-8,-3,-2,4,-4,-1,5,9,-8])
			
			



