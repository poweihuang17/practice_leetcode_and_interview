# 0402 updated. Leetcode passed.
class Solution(object):
    def minCost(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if not costs:
        	return 0
        
        table=[[0]*3 for i in range(len(costs))]

        table[0][0]=costs[0][0]
        table[0][1]=costs[0][1]
        table[0][2]=costs[0][2]

        for i in range(1,len(costs)):
        	table[i][0]=min(table[i-1][1]+costs[i][0], table[i-1][2]+costs[i][0])
        	table[i][1]=min(table[i-1][0]+costs[i][1], table[i-1][2]+costs[i][1])
        	table[i][2]=min(table[i-1][0]+costs[i][2], table[i-1][1]+costs[i][2])

        return min(table[len(costs)-1])

print Solution().minCost