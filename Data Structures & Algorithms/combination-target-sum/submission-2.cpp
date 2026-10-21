class Solution {
public:
    map<vector<int>, int>m;
    void helper(int index, vector<int>&nums, 
    vector<int>&v, int target, vector<vector<int>>&ans){
        if(index == nums.size() and target == 0 and m[v]==0){
            ans.push_back(v);
            m[v]++;
            return;
        }
        if(index>=nums.size() || target<0) return ;

        v.push_back(nums[index]);
        helper(index, nums, v, target - nums[index], ans);
        v.pop_back();
        helper(index+1, nums, v, target, ans);
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        vector<int>v;
        helper(0, nums, v, target, ans);
        return ans;
    }
};
