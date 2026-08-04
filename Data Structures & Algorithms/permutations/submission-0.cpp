class Solution {
   public:
    void permutations(int index, vector<int>& nums, int n, vector<int>& temp,
                      unordered_map<int, int>& m, vector<vector<int>>& ans) {
        if (index >= n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; ++i) {
            if (m[i] == 0) {
                temp.push_back(nums[i]);
                m[i]++;
                permutations(index + 1, nums, n, temp, m, ans);
                m[i]--;
                temp.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        unordered_map<int, int> m;
        vector<int> temp;
        permutations(0, nums, nums.size(), temp, m, ans);
        return ans;
    }
};
