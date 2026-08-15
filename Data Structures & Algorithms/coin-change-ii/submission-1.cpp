class Solution {
public:
    int numOfWays(int index, int n, vector<int>&coins, int amount, 
    vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(index>=n || amount<0) return 0;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int consider = 0;
        if(coins[index]<=amount)
            consider = numOfWays(index, n, coins, amount-coins[index], dp);
        int notConsider = numOfWays(index+1, n, coins, amount, dp);
        return dp[index][amount] = consider+notConsider;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        return numOfWays(0, n, coins, amount, dp);
    }
};
