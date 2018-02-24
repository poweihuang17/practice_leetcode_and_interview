class Solution(object):
    def combinationSum(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        candidates=sorted(candidates,key=lambda k:-k)
        #print candidates

        result=[]
        bag_now=[]
        self.backtrack(candidates,target,0,result,bag_now)
        #print result
        return result

    def backtrack(self,candidates,target,i,result,bag_now):
    	#print (target,i)
    	#print bag_now
    	#print result
    	if target==0:
    		result.append(list(bag_now))
    		#print result
    		return
    	elif i>=len(candidates):
    		return

    	else:
    		if i<len(candidates)-1:
    			self.backtrack(candidates,target,i+1,result,bag_now)
    			for k in range(1,target/candidates[i]+1):
    				for j in range(k):
    					#print "push %d"%candidates[i]
    					bag_now.append(candidates[i])
    				self.backtrack(candidates,target-k*candidates[i],i+1,result,bag_now)
    				for j in range(k):
    					#print "pop %d"%candidates[i]
    					bag_now.pop()
    			return 
    		else:
    			l=target/candidates[i]
    			if target%candidates[i]==0:
    				for m in range(l):
    					bag_now.append(candidates[i])
    				result.append(list(bag_now))
    				#print result
    				for m in range(l):
    					bag_now.pop()
    				return 
    			else:
					return

print Solution().combinationSum([2, 3, 6, 7], 7)