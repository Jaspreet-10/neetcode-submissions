class Solution {
public:
    int helper(int index, int n, vector<int>&nums, int target, 
        map<pair<int, int>, int>&dp){
            if(index == n and target == 0){
                return 1;
            }
            if(index>=n and target!=0) return 0;
            if(dp.find({index, target})!=dp.end()) return dp[{index, target}];
            int sub = helper(index+1, n, nums, target - nums[index], dp);
            int add = helper(index+1, n, nums, target + nums[index], dp);
            return dp[{index, target}] = sub + add;
        }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), sum = 0;
        map<pair<int, int>, int>dp;
        return helper(0, n, nums, target, dp);
    }
};
