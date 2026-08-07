class Solution {
public:
    int numOfWays(int index, int n, vector<int>&nums, int target,
    map<pair<int, int>, int>&dp){
        if(index == n and target == 0) return 1;
        if(index >= n and target!=0) return 0;
        if(dp.find({index, target})!=dp.end()) return dp[{index, target}];
        int plus = numOfWays(index+1, n, nums, target - nums[index], dp);
        int minus = numOfWays(index+1, n, nums, target + nums[index], dp);
        return dp[{index, target}] = plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        target = abs(target);
        map<pair<int, int>, int>dp;
        return numOfWays(0, n, nums, target, dp);
    }
};
