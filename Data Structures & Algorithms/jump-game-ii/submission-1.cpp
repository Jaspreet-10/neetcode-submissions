class Solution {
public:
    int jump(vector<int>& nums) {
        int canReach = 0, maxi = 0, count = 0;
        for(int i = 0 ; i < nums.size() ; ++i){
            if(i == nums.size()-1) return count;
            maxi = max(maxi, nums[i]+i);
            if(i == canReach){
                canReach = maxi;
                ++count;
            }
        }
        return count;
    }
};
