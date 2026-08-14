class Solution {
public:
    int totalWays(int index, int n, vector<int>&dp, vector<int>&cost){
        if(index == n) return 0;
        if(index>=n) return 10001;
        if(dp[index]!=-1) return dp[index];
        int oneJump = cost[index] + totalWays(index+1, n, dp, cost);
        int twoJump = cost[index] + totalWays(index+2, n, dp, cost);
        return dp[index] = min(oneJump, twoJump);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, -1);
        return min(totalWays(0, n, dp, cost), totalWays(1, n, dp, cost));
    }
};
