class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        if len(cost)==0:
        	return 0
        elif len(cost)==1:
        	return cost[0]

        cost_accumulate=[0,0]
        for i in range(2,len(cost)+1):
        	#print i
        	new_cost=min(cost_accumulate[i-2]+cost[i-2],cost[i-1]+cost_accumulate[i-1])
        	cost_accumulate.append(new_cost)
        return cost_accumulate[-1]

s=Solution()
print s.minCostClimbingStairs([10, 15, 20])
print s.minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1])
print s.minCostClimbingStairs([0,0,1,1])