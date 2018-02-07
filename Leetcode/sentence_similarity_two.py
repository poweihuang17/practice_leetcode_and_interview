import collections
class Solution(object):
    def areSentencesSimilarTwo(self, words1, words2, pairs):
        """
        :type words1: List[str]
        :type words2: List[str]
        :type pairs: List[List[str]]
        :rtype: bool
        """
        if len(words1) != len(words2):
            return False
        
        table=collections.defaultdict(set)
        
        #A->B
        #B->A
        
        for pair in pairs:
            
            table[pair[0]].add(pair[1])
            table[pair[0]].add(pair[0])

            table[pair[0]]=table[pair[1]] | table[pair[0]]

            redirection=table[pair[0]]
            for key in table[pair[0]]:
                table[key]=redirection
            

            
            
        
        
        #print table
        
        result=[0 for x in range(len(words1))]
        
        for idx, word1 in enumerate(words1):
            if word1==words2[idx]:
                result[idx]=1
                continue
            if words2[idx] in table[word1]:
                result[idx]=1
        '''    
        for index,debug in enumerate(result):
            if debug==0:
                print index
                print table[words1[index]]
                print table[words2[index]]
        '''
        return all(result)
        

if __name__ == '__main__':
    Solution=Solution()
    print Solution.areSentencesSimilarTwo(["an","extraordinary","meal"],
["one","good","dinner"],
[["great","good"],["extraordinary","good"],["well","good"],["wonderful","good"],["excellent","good"],["fine","good"],["nice","good"],["any","one"],["some","one"],["unique","one"],["the","one"],["an","one"],["single","one"],["a","one"],["truck","car"],["wagon","car"],["automobile","car"],["auto","car"],["vehicle","car"],["entertain","have"],["drink","have"],["eat","have"],["take","have"],["fruits","meal"],["brunch","meal"],["breakfast","meal"],["food","meal"],["dinner","meal"],["super","meal"],["lunch","meal"],["possess","own"],["keep","own"],["have","own"],["extremely","very"],["actually","very"],["really","very"],["super","very"]])