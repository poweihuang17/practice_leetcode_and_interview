class Solution(object):
    def kEmptySlots(self, flowers, k):
        """
        :type flowers: List[int]
        :type k: int
        :rtype: int
        """
        f=[False]*len(flowers)

        def isValid(bloom_index, f,k):
        	f[bloom_index]=True

        	k_empty_right=True

        	for i in range(bloom_index+1,bloom_index+k+1):	
        		if i>=len(f) or f[i]:
        			k_empty_right=False
        			break
        	if k_empty_right and bloom_index+k+1<len(f) and f[bloom_index+k+1]:
        		return True

        	k_empty_left=True
        	for i in range(bloom_index-k,bloom_index):
        		if i<0 or f[i]:
        			k_empty_left=False
        			break
        	
        	if k_empty_left and bloom_index-k-1>=0 and f[bloom_index-k-1]:
        		return True

        	
        	
        	return False


        for i in range(len(flowers)):
        	if isValid(flowers[i]-1,f,k):
        		return i+1
        return -1

print Solution().kEmptySlots([1,3,2],1)
print Solution().kEmptySlots([1,2,3],1)

