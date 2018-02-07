import itertools
class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        if len(cost)==0:
        	return 0
        cost+=[0]
        dp=[0] * len(cost)
        dp[0]=cost[0]
        dp[1]=cost[1]
        for i in itertools.islice(range(len(cost)),2,None):
        	#print i
        	dp[i]=min(dp[i-2], dp[i-1])+cost[i]

        return dp[len(cost)-1]

s=Solution()
print s.minCostClimbingStairs([10, 15, 20])
print s.minCostClimbingStairs([1, 100, 1, 1, 1, 100, 1, 1, 100, 1])
