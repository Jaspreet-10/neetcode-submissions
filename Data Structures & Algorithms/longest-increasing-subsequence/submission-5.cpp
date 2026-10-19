class Solution {
public:
    int helper(int index, int n, vector<int>&nums, 
    vector<vector<int>>&dp, int prev){
        if(index>=n) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];

        int consider = 0;
        if(prev == -1 || nums[index]>nums[prev]){
            consider = 1+helper(index+1, n, nums, dp, index);
        }

        int notConsider = helper(index+1, n, nums, dp, prev);
        return dp[index][prev+1] = max(consider, notConsider);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), prev = -1;
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(0, n, nums, dp, prev);
    }
};
