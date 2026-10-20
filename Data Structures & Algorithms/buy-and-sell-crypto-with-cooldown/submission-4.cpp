class Solution {
public:
    int helper(int index, int n, vector<int>&prices, bool canBuy, 
        vector<vector<int>>&dp){
            if(index>=n) return 0;
            if(dp[index][canBuy]!=-1) return dp[index][canBuy];

            int profit = 0, idle = 0;
            if(canBuy){
                profit = -prices[index] + helper(index+1, n, prices, false, dp);
                idle = helper(index+1, n, prices, canBuy, dp);
            }
            else{
                profit = prices[index] + helper(index+2, n, prices, true, dp);
                idle = helper(index+1, n, prices, canBuy, dp);
            }

            return dp[index][canBuy] = max(profit, idle);
        }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        bool canBuy = true;
        vector<vector<int>>dp(n, vector<int>(2, -1));
        return helper(0, n, prices, canBuy, dp);
    }
};
