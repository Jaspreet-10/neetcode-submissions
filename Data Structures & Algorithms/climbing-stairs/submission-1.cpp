class Solution {
public:
    int countWays(int index, int n, vector<int>&dp){
        if(index == n) return 1;
        if(index>n) return 0;
        if(dp[index]!=0) return dp[index];
        int oneStep = countWays(index+1, n, dp);
        int twoSteps = countWays(index+2, n, dp);
        dp[index] = oneStep+twoSteps;
        return dp[index];
    }
    int climbStairs(int n) {
        vector<int>dp(n, 0);
        return countWays(0, n, dp);
    }
};
