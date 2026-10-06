class Solution {
public:
    int findMaxProfit(int index, int n, vector<int>&prices, bool buy, 
        vector<vector<int>>&dp){
            if(index>=n) return 0;
            if(dp[index][buy]!=-1) return dp[index][buy];
            int profit = 0, idle = 0;
            if(buy){
                profit = -prices[index] + 
                    findMaxProfit(index+1, n, prices, false, dp);
                idle = findMaxProfit(index+1, n, prices, buy, dp);
            }else{
                profit = prices[index] + 
                    findMaxProfit(index+2, n, prices, true, dp);
                idle = findMaxProfit(index+1, n, prices, buy, dp);
            }
            return dp[index][buy] = max(profit, idle);
        }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool buy = true;
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return findMaxProfit(0, n, prices, buy, dp);
    }
};
