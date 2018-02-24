class Solution(object):
    def wordBreakable(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """

        def canBreak(s,m,wordDict):
        	if s in m:
        		return m[s]
        	if s in wordDict:
        		m[s]=True
        		return True

        	
        	m[s]=any( s[i:] in wordDict and canBreak(s[0:i],m,wordDict) for i in range(1,len(s)))
        	return m[s]

        return canBreak(s,{},set(wordDict))

    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        if not wordDict:
        	return []
        if not self.wordBreakable(s,wordDict):
        	return []
        d={}
        minimum=float('inf')
        for word in wordDict:
        	d[word]=True
        	minimum=min(minimum, len(word))
        bag_now=[0]
        result=[]
        self.wordBreak_Backtrack(s,d,0,result,bag_now,minimum)
        final=[]
        
        for r in result:
        	temp=[]
        	for i in range(0,len(r)-1):
        		temp.append(s[r[i]:r[i+1]])
        	final.append(' '.join(temp))
        
        return final

    def wordBreak_Backtrack(self,s,d,i,result,bag_now,minimum):
    	return_status=False
    	for j in range(i+minimum,len(s)+1):
    		if s[i:j] in d:
    			if d[s[i:j]]==True:
    				bag_now.append(j)
    				if j==len(s):
    					result.append(list(bag_now))
    					bag_now.pop()
    					return True
    				else:
    					status=self.wordBreak_Backtrack(s,d,j,result,bag_now,minimum)
    					if status:
    						return_status=True
    				bag_now.pop()
    	return return_status
    			

print Solution().wordBreak("catsanddog",["cat", "cats", "and", "sand", "dog"])



