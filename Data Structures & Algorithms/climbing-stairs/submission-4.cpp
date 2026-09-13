class Solution {
public:
    int helper(int index, int n, vector<int>&dp){
        if(index == n) return 1;
        if(index>n) return 0;
        if(dp[index]!=0) return dp[index];
        int oneStep = helper(index+1, n, dp);
        int twoSteps = helper(index+2, n, dp);
        return dp[index] = oneStep + twoSteps;
    }
    int climbStairs(int n) {
        vector<int>dp(n, 0);
        return helper(0, n, dp);
    }
};
