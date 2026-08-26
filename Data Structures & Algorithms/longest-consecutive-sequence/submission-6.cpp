class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin(), nums.end());
        int n = s.size(), longestStreak = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(s.find(nums[i]-1)==s.end()){
                int streak = 0, element = nums[i];
                while(s.find(element)!=s.end()){
                    ++streak;
                    ++element;
                }
                longestStreak = max(streak, longestStreak); 
            }
        }
        return longestStreak;
    }
};
