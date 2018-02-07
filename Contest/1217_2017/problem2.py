import collections

class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """

        counter=collections.Counter(licensePlate.lower())
        min_length=float('inf')
        min_index=-1
        for index, word in enumerate(words):
        	word_count=collections.Counter(word)
        	test=True
        	for target in counter:

        		if target.isalpha() and word_count[target]< counter[target]:
        			test=False

        	if test==True:
        		#print word
        		if min_length>len(word):
        			min_index=index
        			min_length=len(word)

        return words[min_index]


s=Solution()
print s.shortestCompletingWord("1s3 PSt", ["step", "steps", "stripe", "stepple"])
print s.shortestCompletingWord("1s3 456",  ["looks", "pest", "stew", "show"])
