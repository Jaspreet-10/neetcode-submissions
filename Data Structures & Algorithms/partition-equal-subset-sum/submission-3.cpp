class Solution {
public:
    bool helper(int index, int n, vector<int>&nums, 
    vector<vector<int>>&dp, int sum){
        if(index>=n || sum<0) return 0;
        
        if(sum == 0) return 1;
        
        if(dp[index][sum]!=-1) return dp[index][sum];
        bool consider = false;
        if(nums[index]<=sum)
        consider = helper(index+1, n, nums, dp, sum - nums[index]);
        bool notConsider = helper(index+1, n, nums, dp, sum);

        return dp[index][sum] = consider or notConsider;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0 ; i < n ; ++i) sum+=nums[i];
        if(sum%2 != 0) return false;
        sum/=2;
        vector<vector<int>>dp(n, vector<int>(sum+1, -1));
        return helper(0, n, nums, dp, sum);
    }
};
