class Solution {
public:
    vector<vector<int>>findSubsets(int index, vector<int>&nums, vector<int>temp, 
    vector<vector<int>>&ans){
        if(index>=nums.size()){
            ans.push_back(temp);
            return ans;
        }
        temp.push_back(nums[index]);
        findSubsets(index+1, nums, temp, ans);
        temp.pop_back();
        findSubsets(index+1, nums, temp, ans);
        return ans;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        return findSubsets(0, nums, temp, ans);
    }
};
