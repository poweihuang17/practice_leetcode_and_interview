class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int mini=INT_MAX;
        int max_profit=INT_MIN;
        for(int i=0;i<prices.size();i++)
        {
        	mini=min(prices[i],mini);
        	max_profit=max(prices[i]-mini,max_profit);
        }
        return max_profit;
    }
    
};