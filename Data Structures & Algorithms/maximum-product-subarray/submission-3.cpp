class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0, j = nums.size()-1, maxi = INT_MIN, pref = 1, suff = 1;
        while(i<nums.size() && j>=0){
            pref = pref*nums[i];
            suff = suff*nums[j];
            maxi = max(maxi, max(pref, suff));
            if(suff == 0) suff = 1;
            if(pref == 0) pref = 1;
            ++i, --j;
        }
        return maxi;
    }
};
