class Solution {
public:
    int helper(int index, int n, vector<int>&dp, vector<int>&nums){
        if(index >= n) return 0;
        if(dp[index]!=0) return dp[index];
        int oneStep = nums[index] + helper(index+2, n, dp, nums);
        int twoSteps = helper(index+1, n, dp, nums);
        return dp[index] = max(oneStep,twoSteps);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 0);
        return max(helper(0,  n, dp, nums), helper(1,  n, dp, nums));
    }
};
