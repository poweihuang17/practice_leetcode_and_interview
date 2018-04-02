class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<int> own(prices.size()+1,-50001);
        vector<int> sell(prices.size()+1,0);
        for(int i=1;i<=prices.size();i++)
        {
        	own[i]=max(sell[i-1]-prices[i-1],own[i-1]);
        	sell[i]=max(own[i-1]+prices[i-1]-fee,sell[i-1]);
        }
        return sell[prices.size()];
    }
};