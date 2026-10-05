class Solution {
public:
    int helper(int index, int n, vector<int>&coins, int amount, 
        vector<vector<int>>&dp){
            if(amount == 0) return 0;
            if(index>=n || amount<0) return 10001;
            if(dp[index][amount]!=-1) return dp[index][amount];
            int consider = 1 + helper(index, n, coins, 
            amount-coins[index], dp);
            int notConsider = helper(index+1, n, coins, 
                amount, dp);
            return dp[index][amount] = min(consider,notConsider);
        }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = helper(0, n, coins, amount, dp);
        if(ans == 10001) return -1;
        return ans;
    }
};
