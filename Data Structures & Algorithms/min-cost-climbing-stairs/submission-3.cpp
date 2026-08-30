class Solution {
public:
    int minCountStairs(int index, int n, vector<int>&cost, vector<int>&dp){
        if(index>n) return 10001;
        if(index == n) return 0;
        if(dp[index]!=0) return dp[index];
        int oneStep = cost[index] + minCountStairs(index+1, n, cost, dp);
        int twoSteps = cost[index] + minCountStairs(index+2, n, cost, dp);
        return dp[index] = min(oneStep, twoSteps);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, 0);
        return min(minCountStairs(0, n, cost, dp), dp[1]);
    }
};
