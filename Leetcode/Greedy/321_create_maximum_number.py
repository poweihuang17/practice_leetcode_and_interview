class Solution(object):
    def maxNumber(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[int]
        """

        def MaxArray(nums1,k):
        	stack=[]
        	remaining=len(nums1)
        	for s in nums1:
        		while stack and (remaining+len(stack))>k and stack[-1]<s:
        				stack.pop()
        		
        		if len(stack)<k:
        			stack.append(s)
        		remaining-=1

        	return stack

        def merge(nums1, nums2,k):
        	
        	index1=0
        	index2=0
        	result=[]
        	for i in range(k):
        		if index1<len(nums1) and index2<len(nums2):
        			if greater(nums1,nums2,index1,index2):
        				result.append(nums1[index1])  
        				index1+=1

        			else:
        				result.append( nums2[index2] ) 
        				index2+=1

        		elif index1<len(nums1):
        			result.append(nums1[index1])  
        			index1+=1

        		elif index2<len(nums2):
         			result.append(nums2[index2])  
        			index2+=1       			

        	return result

        def greater(nums1, nums2,index1,index2):
        	while index1 < len(nums1) and index2<len(nums2) and nums1[index1]==nums2[index2]:
        		index1+=1
        		index2+=1

        	return index2==len(nums2) or (index1!=len(nums1) and nums1[index1]>nums2[index2])

        ans=[0]*k
        for i in range(k+1):
        	if len(nums1)>=i and len(nums2)>=(k-i):
        		temp=merge(MaxArray(nums1,i), MaxArray(nums2,k-i),k)
        		#print temp
        		ans=ans if greater(ans,temp,0,0) else temp

        return ans
        
        

s= Solution()
print s.maxNumber([1,2],[], 2)


       

