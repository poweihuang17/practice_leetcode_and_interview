class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        if not prices:
        	return 0

        cur,nxt=0,1
       	first_buy=[float('-inf'),0]
       	first_buy_and_sell=[0,0]
       	second_buy=[float('-inf'),0]
       	second_buy_and_sell=[0,0]

       	for price in prices:
       		first_buy[nxt]=max(first_buy[cur],-price)
       		first_buy_and_sell[nxt]=max(first_buy_and_sell[cur], price+first_buy[cur])
       		second_buy[nxt]=max(second_buy[cur], first_buy_and_sell[cur]-price)
       		second_buy_and_sell[nxt]=max(second_buy_and_sell[cur], price+second_buy[cur])
       		cur, nxt= nxt, cur

       	return second_buy_and_sell[cur]

print Solution().maxProfit([1])
print Solution().maxProfit([1,2,4])



