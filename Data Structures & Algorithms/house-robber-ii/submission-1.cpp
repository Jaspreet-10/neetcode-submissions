class Solution {
public:
    int countWays(int index, int n, vector<int>&dp, vector<int>&cost){
        if(index >= n) return 0;
        if(dp[index]!=0) return dp[index];
        int oneStep = cost[index] + countWays(index+2, n, dp, cost);
        int twoSteps = countWays(index+1, n, dp, cost);
        dp[index] = max(oneStep, twoSteps);
        return dp[index];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int>dp1(n, 0);
        vector<int>dp2(n, 0);
        return max(countWays(0, n-1, dp1, nums), countWays(1, n, dp2, nums));
    }
};
