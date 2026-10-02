class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(), nums.end());
        int longestStreak = 0;
        for(auto it : s){
            if(s.find(it-1)!=s.end()) continue;
            int num = it;
            int streak = 0;
            while(s.find(num)!=s.end()){
                ++streak;
                longestStreak = max(streak, longestStreak);
                ++num;
            }
        }
        return longestStreak;
    }
};
