class Solution {
public:
    int findMaxProfit(int index, int n, vector<int>& prices, bool canBuy, 
    vector<vector<int>>&dp){
        if(index>=n) return 0;
        if(dp[index][canBuy]!=-1) return dp[index][canBuy];
        int idle = 0, profit = 0;
        if(canBuy){
            idle = findMaxProfit(index+1, n, prices, canBuy, dp);
            profit=-prices[index] + findMaxProfit(index+1, n, prices, false, dp);
        }else{
            idle = findMaxProfit(index+1, n, prices, canBuy, dp);
            profit=prices[index] + findMaxProfit(index+2, n, prices, true, dp);
        }
        return dp[index][canBuy] = max(idle, profit);
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n, vector<int>(2, -1));
        bool canBuy = true, idle = true;
        return findMaxProfit(0, n, prices, canBuy, dp);
    }
};
