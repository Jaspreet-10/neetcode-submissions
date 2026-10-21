class Solution {
public:
    void getSubsets(int index, vector<int>&nums, int n, vector<int>&temp, map<vector<int>, int>&m, vector<vector<int>>&ans){
        if(index>=n){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        getSubsets(index+1, nums, n, temp, m, ans);
        temp.pop_back();
        while (index != nums.size() - 1 && nums[index] == nums[index + 1])
            index++;
        getSubsets(index+1, nums, n, temp, m, ans);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        map<vector<int>, int>m;
        sort(nums.begin(), nums.end());
        getSubsets(0, nums, nums.size(), temp, m, ans);
        return ans;
    }
};
