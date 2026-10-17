class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int>s(nums.begin(), nums.end());
        int longestStreak = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            int num = nums[i];
            if(s.find(num-1)==s.end()){
                int streak = 0;
                while(s.find(num)!=s.end()){
                    ++streak;
                    ++num;
                }
                longestStreak = max(streak, longestStreak);
            }
        }
        return longestStreak;
    }
};
