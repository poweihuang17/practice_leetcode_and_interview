class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
        	return 0
        elif len(prices)==1:
        	return 0
        elif len(prices)==2:
        	return (prices[1]-prices[0]) if prices[1]-prices[0]>=0 else 0

        table=[(float('-inf'),float('-inf'),float('-inf')) for i in range(len(prices))]

        table[0],table[1]=(0,-prices[0],0),( (prices[1]-prices[0]) if prices[1]-prices[0] >=0 else 0,-min(prices[0],prices[1]),0)
        
        for i in range(2,len(prices)):
        	table[i]=( table[i-1][1]+prices[i]  , max(table[i-1][2]-prices[i],table[i-2][0]-prices[i],table[i-1][1])  , max(table[i-2][0],table[i-2][2],table[i-2][1]+prices[i-1],table[i-1][2],table[i-1][0]) )

        return max(table[-1][0],table[-1][2])

print Solution().maxProfit( [1, 2, 3, 0, 2])