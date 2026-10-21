class Solution {
public:
    void helper(int index, vector<int>&nums, vector<int>&v, 
    vector<vector<int>>&ans, unordered_map<int, int>&m){
        if(index>=nums.size()){
            ans.push_back(v);
            return;
        }

        for(int i = 0 ; i < nums.size() ; ++i){
            if(m[i] == 0){
                v.push_back(nums[i]);
                m[i]++;
                helper(index+1, nums, v, ans, m);
                v.pop_back();
                m[i]--;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>v;
        unordered_map<int, int>m;
        helper(0, nums, v, ans, m);
        return ans;
    }
};
