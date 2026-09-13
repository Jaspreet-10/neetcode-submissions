class Solution {
public:
    int helper(int index, int n, vector<int>&nums, vector<int>&dp){
        if(index>=n) return 0;  
        if(dp[index]!=-1) return dp[index];
        int oneJump = nums[index] + helper(index+2, n, nums, dp);
        int twoJumps = helper(index+1, n, nums, dp);
        return dp[index] = max(oneJump, twoJumps);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, -1);
        return helper(0, n, nums, dp);   
    }
};
