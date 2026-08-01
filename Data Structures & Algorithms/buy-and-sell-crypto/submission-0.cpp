class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0], profit = 0, n = prices.size();
        for(int i = 1 ; i < n ; ++i){
            if(prices[i]>buy){
                profit = max(profit, prices[i] - buy);
            }
            if(prices[i]<buy) buy = prices[i];
        }
        return profit;
    }
};
