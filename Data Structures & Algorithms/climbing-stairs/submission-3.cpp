class Solution {
public:
    int countStairs(int index, int n, vector<int>&dp){
        if(index>n) return 0;
        if(index == n) return 1;
        if(dp[index]!=0) return dp[index];
        int oneStep = countStairs(index+1, n, dp);
        int twoSteps = countStairs(index+2, n, dp);
        return dp[index] = oneStep + twoSteps;
    }
    int climbStairs(int n) {
        if(n == 1) return 1;
        vector<int>dp(n , 0);
        return countStairs(0, n, dp);
    }
};
