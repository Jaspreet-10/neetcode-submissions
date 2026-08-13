class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int longestStreak = 0;
        for (int i = 0; i < nums.size(); ++i) s.insert(nums[i]);
        for (auto it : s) {
            if (s.find(it - 1) == s.end()) {
                int currentStreak = 1;
                int currentNum = it + 1;
                while (s.find(currentNum) != s.end()) {
                    currentStreak += 1;
                    currentNum += 1;
                }
                longestStreak = max(longestStreak, currentStreak);
            }
        }
        return longestStreak;
    }
};
