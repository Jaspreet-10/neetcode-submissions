class Solution {
public:
    bool canJump(vector<int>& nums) {
        int canReach = 0, maxi = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(i>canReach) return false;
            maxi = max(maxi, nums[i]+i);
            if(i == canReach){
                canReach = maxi;
                maxi = 0;
            }
        }
        return true;
    }
};
