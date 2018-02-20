class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """

        table=[[0]*(len(word1)+1) for i in range(len(word2)+1)]

        #Boundary condition
        for i in range(len(word1)+1):
        	table[0][i]=i

        for  i in range(len(word2)+1):
        	table[i][0]=i


        #General condition

        for i in range(1,len(word1)+1):
        	for j in range(1,len(word2)+1):
        		if word1[i-1]==word2[j-1]:
        			table[j][i]=table[j-1][i-1]
        		else:
        			table[j][i]=min(table[j-1][i-1], table[j-1][i],table[j][i-1])+1
        '''
        for i in range(len(word2)+1):
        	print table[i]
        '''
        return table[len(word2)][len(word1)]
s=Solution()
print s.minDistance("abc","aaa")
