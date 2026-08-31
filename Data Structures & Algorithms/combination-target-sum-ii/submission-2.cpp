class Solution {
   public:
    void findTarget(int index, vector<int>& candidates, int n, int target, vector<int>& temp,
                    vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (index >= candidates.size()) return;
        if (candidates[index] <= target) {
            temp.push_back(candidates[index]);
            findTarget(index + 1, candidates, n, target - candidates[index], temp, ans);
            temp.pop_back();
            while (index != candidates.size() - 1 && candidates[index] == candidates[index + 1]) {
                index++;
            }
        }
        findTarget(index + 1, candidates, n, target, temp, ans);
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        findTarget(0, candidates, candidates.size(), target, temp, ans);
        return ans;
    }
};
