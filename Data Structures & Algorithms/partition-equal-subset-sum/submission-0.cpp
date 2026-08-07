class Solution {
public:
    // bool flag = 
    bool checkPartition(int index, int n, vector<int>&nums, int totalSum,   
    vector<vector<int>>&dp){
        if(index>=n || totalSum<0) return 0;
        if(totalSum == 0) return true;
        if(dp[index][totalSum]!=-1) return dp[index][totalSum];
        bool consider = false;
        if(nums[index]<=totalSum)
            consider = checkPartition(index+1, n, nums, totalSum-nums[index], dp); 
            if(consider) return true;
        bool notConsider = checkPartition(index+1, n, nums, totalSum, dp);
        return dp[index][totalSum] = consider or notConsider;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0, n = nums.size();
        for(int i = 0 ; i < n ; ++i){
            totalSum+=nums[i];
        }
        if(totalSum%2!=0) return false;
        totalSum/=2;
        vector<vector<int>> dp(n, vector<int>(totalSum + 1, -1));
        return checkPartition(0, n, nums, totalSum, dp);
    }
};
