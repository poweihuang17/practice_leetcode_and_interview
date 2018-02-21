class Solution(object):
    def maxProfit(self, k, prices):
        """
        :type k: int
        :type prices: List[int]
        :rtype: int
        """
        if not prices or k==0:
        	return 0
        if k>len(prices):
        	k=len(prices)

        if k >= len(prices)/2:
        	sum=0
        	for i in range(len(prices)-1):
        		if prices[i+1]>prices[i]:
        			sum+=(prices[i+1]-prices[i])
        	return sum


        table=[[(float('-inf'),0)]*k for i in range(2)]
        cur,nxt=0,1

        for i in range(len(prices)):
        	for j in range(1):
        		table[nxt][j]=(max(table[cur][j][0], -prices[i])), max(table[cur][j][1],prices[i]+table[cur][j][0])
        	for j in range(1,k):
        		table[nxt][j]=(max(table[cur][j][0], table[cur][j-1][1]-prices[i])), max(table[cur][j][1],prices[i]+table[cur][j][0])
        	cur,nxt=nxt,cur

        return table[cur][k-1][1]
        
print Solution().maxProfit(2,[1, 2, 3, 4])
