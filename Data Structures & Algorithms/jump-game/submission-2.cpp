class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, maxi = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            maxi = max(maxi, i+nums[i]);
            if(i>reach) return false;
            if(i == reach){
                reach = maxi;
                maxi = 0;
            }
        }
        return true;
    }
};
