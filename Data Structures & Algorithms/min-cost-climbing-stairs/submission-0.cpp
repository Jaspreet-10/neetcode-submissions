class Solution {
public:
    int countWays(int index, int n, vector<int>&dp, vector<int>&cost){
        if(index == n) return 0;
        if(index>n) return 10001;
        if(dp[index]!=0) return dp[index];
        int oneStep = cost[index] + countWays(index+1, n, dp, cost);
        int twoSteps = cost[index]+ countWays(index+2, n, dp, cost);
        dp[index] = min(oneStep, twoSteps);
        return dp[index];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, 0);
        return min(countWays(0, n, dp, cost), dp[1]);
    }
};
