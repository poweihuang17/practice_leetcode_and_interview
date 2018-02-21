class Solution(object):
    def wordBreak(self, s, wordDict):
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

print Solution().wordBreak("leetcode", ["leet", "code"])