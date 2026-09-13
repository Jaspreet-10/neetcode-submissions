class Solution {
public:
    int findLengthOfLIS(int index, int n, int prev, vector<int>&nums,         
    vector<vector<int>>&dp){
        if(index>=n) return 0;
        if(dp[index][prev+1]!=-1) return dp[index][prev+1];
        int consider = 0;
        if(prev == -1 || nums[index]>nums[prev]){
            consider = 1+findLengthOfLIS(index+1, n, index, nums, dp);
        }
        int notConsider = findLengthOfLIS(index+1, n, prev, nums, dp);
        return dp[index][prev+1] = max(consider, notConsider);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        int ans = findLengthOfLIS(0, n, -1, nums, dp);
        return ans;
    }
};
