class Solution {
public:
    int findCoins(int index, vector<int>&coins, int n, 
    vector<vector<int>>&dp, int amount){
         if(amount == 0) return 0;
        if(index>=n || amount<0) return 10001;
        if(dp[index][amount]!=0) return dp[index][amount];
        int consider = 1 + findCoins(index, coins, n, dp, amount-coins[index]);
        int notConsider = findCoins(index+1, coins, n, dp, amount);
        return dp[index][amount] = min(consider, notConsider);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        int ans = findCoins(0, coins, n, dp, amount);
        if(ans == 10001) return -1;
        return ans;
    }
};
