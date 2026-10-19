class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size()-1;
        int jump = nums[0], maxi = 0, steps = 0;
        for(int i = 1 ; i < nums.size() ; ++i){
            maxi = max(maxi, nums[i] + i);
            if(i == n) return steps+1;
            if(i == jump){
                ++steps;
                jump = maxi;
                maxi = 0;
            }
        }
        return steps;
    }
};
