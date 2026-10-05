class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int i = 0, j = nums.size()-1, n = j;
        int suff = 1, pref = 1, maxi = INT_MIN;
        while(i<=n and j>=0){
            pref*=nums[i];
            suff*=nums[j];
            maxi = max(maxi, max(pref, suff));
            if(suff == 0) suff = 1;
            if(pref == 0) pref = 1;
            ++i, --j;
        }
        return maxi;
    }
};
