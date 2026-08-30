class Solution {
public:
    int minCountStairs(int index, int n, vector<int>&nums, vector<int>&dp){
        if(index>=n) return 0;
        if(dp[index]!=0) return dp[index];
        int consider = nums[index] + minCountStairs(index+2, n, nums, dp);
        int notConsider = minCountStairs(index+1, n, nums, dp);
        return dp[index] = max(consider, notConsider);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp1(n, 0);
        vector<int>dp2(n, 0);
        return max(minCountStairs(0, n-1, nums, dp1), 
        minCountStairs(1, n, nums, dp2));
    }
};
