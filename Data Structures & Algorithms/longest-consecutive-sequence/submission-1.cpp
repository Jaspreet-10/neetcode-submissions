class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), longestStreak = 0;
        unordered_set<int>s;
        for(int i = 0 ; i < n ; ++i){
            s.insert(nums[i]);
        }
        for(auto it : s){
            int currentElement = it;
            int streak = 1;
            while(s.find(currentElement-1)!=s.end()){
                --currentElement;
                ++streak;
            }
            longestStreak = max(longestStreak, streak);
        }
        return longestStreak;
    }
};
