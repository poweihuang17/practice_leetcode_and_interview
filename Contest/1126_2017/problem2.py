class Solution(object):
    def areSentencesSimilar(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        
        result=[0 for x in range(len(words1))]
        
        for idx, word1 in enumerate(words1):
            if word1==words2[idx]:
                result[idx]=1
                continue
            for pair in pairs:
                if word1==pair[0] and words2[idx]==pair[1]:
                    result[idx]=1
                elif word1==pair[1] and words2[idx]==pair[0]:
                    result[idx]=1
        y=0
        for x in result:
            y+=x
        
        if y==len(words1):
            return True
        else:
            return False

if __name__ == '__main__':
    Solution=Solution()
    print Solution.areSentencesSimilar(["great","acting","skills"],["fine","drama","talent"],[["great","fine"],["drama","acting"],["skills","talent"]])