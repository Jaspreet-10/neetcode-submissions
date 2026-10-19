class Solution {
public:
    bool canJump(vector<int>& nums) {
        int jump = 0, maxi = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            maxi = max(maxi, nums[i] + i);
            if(i>jump) return false;
            if(i == jump){
                jump = maxi;
                maxi = 0;
            }
        }
        return true;
    }
};
