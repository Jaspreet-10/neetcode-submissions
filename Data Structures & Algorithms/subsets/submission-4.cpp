class Solution {
public:
    void makeSubsets(int index, vector<int>&nums, 
    vector<int>&v, vector<vector<int>>&ans){
        if(index == nums.size()){
            ans.push_back(v);
            return;
        }
        v.push_back(nums[index]);
        makeSubsets(index+1, nums, v, ans);
        v.pop_back();
        makeSubsets(index+1, nums, v, ans);
        return ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        makeSubsets(0, nums, v, ans);
        return ans;
    }
};
