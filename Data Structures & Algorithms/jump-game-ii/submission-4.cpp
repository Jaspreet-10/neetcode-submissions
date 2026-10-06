class Solution {
public:
    int jump(vector<int>& nums) {
        int reach = 0, maxi = 0, count = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            maxi = max(maxi, i+nums[i]);
            if(i == nums.size()-1) return count;
            if(i == reach){
                reach = maxi;
                ++count;
            }
        }
        return count;
    }
};
