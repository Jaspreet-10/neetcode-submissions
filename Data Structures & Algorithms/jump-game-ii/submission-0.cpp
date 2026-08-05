class Solution {
public:
    int jump(vector<int>& nums) {
        int maxReach = 0, reached = 0, jumps = 0;
        for(int i = 0 ; i < nums.size()-1 ; ++i){
            if(i>maxReach) return -1;
            maxReach = max(maxReach, nums[i]+i);
            if(i == reached){
                reached = maxReach;
                ++jumps;
            }
        }
        return jumps;
    }
};
