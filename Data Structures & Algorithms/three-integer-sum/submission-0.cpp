class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i = 0, n = nums.size();
        vector<vector<int>> results;
        sort(nums.begin(), nums.end());
        while(i<n){
            int j = i+1, k = n-1;
            while(j<k){
                cout<<nums[i]<<" "<<nums[j]<<" "<<nums[k]<<"\n";
                if((nums[i]+nums[j]+nums[k]) == 0){
                    results.push_back({nums[i], nums[j], nums[k]});
                    ++j, --k;
                while(j<n and nums[j] == nums[j-1]) ++j;
                while(k>=0 and nums[k] == nums[k+1]) --k;
                }
                else if(nums[i]+nums[j]+nums[k] > 0) --k;
                else ++j;
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1]) ++i;
            ++i;
        }
        return results;
    }
};
