import collections
class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        if not s:
        	return 0

        counter=collections.defaultdict(int)
        left=0
        max_length=float('-inf')

        for i in range(len(s)):
        	counter[s[i]]+=1

        	while len(counter.keys())>k:
        		counter[s[left]]-=1
        		if counter[s[left]]==0:
        			del counter[s[left]]
        		left+=1
        	max_length=max(max_length, i-left+1)
        return max_length

print Solution().lengthOfLongestSubstringKDistinct("eceba",2)

