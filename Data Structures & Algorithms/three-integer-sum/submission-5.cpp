class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        while(i<n){
            int k = i+1, j = n-1;
            while(k<j){
            if(nums[i] + nums[j] + nums[k] == 0) {
                ans.push_back({nums[i], nums[j], nums[k]});
             ++k, --j;
             while(k<n and nums[k] == nums[k-1]) ++k;
             while(j>=0 and nums[j] == nums[j+1]) --j;
            }
            else if(nums[i] + nums[j] + nums[k] > 0){
                --j;
            }
            else{
                ++k;
                }
            }
            while(i<n-1 and nums[i] == nums[i+1]) ++i;
            ++i;
        }
        return ans;
    }
};
