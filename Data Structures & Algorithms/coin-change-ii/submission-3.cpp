class Solution {
public:
    int coinChange(int index, int n, vector<int>&coins, vector<vector<int>>&dp, 
        int amount){
        if(amount == 0) return 1;
        if(index>=n || amount<0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int consider = 0;
        if(coins[index]<=amount){
            consider = coinChange(index, n, coins, dp, amount - coins[index]);
        }
        int notConsider = coinChange(index+1, n, coins, dp, amount);
        return dp[index][amount] = consider + notConsider;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return coinChange(0, n, coins, dp, amount);
    }
};
