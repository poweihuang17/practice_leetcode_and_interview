class Solution(object):
    def minCostII(self, costs):
        """
        :type costs: List[List[int]]
        :rtype: int
        """
        if not costs:
        	return 0
        
        table=[[0]*len(costs[0]) for i in range(len(costs))]

        for i in range(len(costs[0])):
        	table[0][i]=costs[0][i]
	        

        for i in range(1,len(costs)):
        	temp=float('inf')
        	for j in range(len(costs[0])):
        		if j==i:
        			continue
        		else:
        			temp=min(table[i-1][j],temp)
        	
        	table[i][j]=temp+costs[i][j]

        return min(table[len(costs)-1])