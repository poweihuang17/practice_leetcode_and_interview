class Solution(object):
    def canWin(self, s):
        """
        :type s: str
        :rtype: bool
        """
    	
    	return self.canWin_memory(s,{})

    def canWin_memory(self,s,hash):
    	if s in hash:
    		return hash[s]

    	
    	for i in range(0,len(s)-1):
    		if s[i:i+2]!="++":
    			continue
    		else:
    			news=s[:i]+'--'+s[i+2:]
    			#print news    			
    			if ( not self.canWin_memory(news,hash)):
    				hash[s]=True
    				return True
    			
    	

    	hash[s]=False
    	return False

print Solution().canWin("++++")
print Solution().canWin("++-+")
print Solution().canWin("+--+")




