class Solution {
public:
    int totalWays(int index, int n, vector<int>&dp){
        if(index == n) return 1;
        if(index>=n) return 0;
        if(dp[index]!=-1) return dp[index];
        int oneJump = totalWays(index+1, n, dp);
        int twoJump = totalWays(index+2, n, dp);
        return dp[index] = oneJump + twoJump;
    }
    int climbStairs(int n) {
        vector<int>dp(n, -1);
        return totalWays(0, n, dp);
    }
};
