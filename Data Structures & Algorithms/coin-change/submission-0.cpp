class Solution {
public:
    int findWays(int index, int n, vector<int>&coins, vector<vector<int>>&dp, 
    int amount){
        if(amount == 0) return 0;
        if(index>=n || amount<0) return 10001;
        if(dp[index][amount]!=-1) return dp[index][amount];
        int consider = 1 + findWays(index, n, coins, dp, amount-coins[index]);
        int notConsider = findWays(index+1, n, coins, dp, amount);
        return dp[index][amount] = min(consider, notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = findWays(0, n, coins, dp, amount);
        if(ans == 10001) return -1;
        return ans;
    }
};
