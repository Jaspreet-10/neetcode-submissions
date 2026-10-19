class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size()-1;
        int jump = 0, maxi = 0, steps = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            maxi = max(maxi, nums[i] + i);
            if(i == n) return steps;
            if(i == jump){
                ++steps;
                jump = maxi;
            }
        }
        return steps;
    }
};
