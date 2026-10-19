class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN, suff = 1, pref = 1, n = nums.size();
        int i = 0, j = nums.size()-1;
        while(i<n and j>=0){
            pref*=nums[i];
            suff*=nums[j];
            maxi = max(maxi, max(pref, suff));
            if(pref == 0) pref = 1;
            if(suff == 0) suff = 1;
            ++i, --j; 
        }
        return maxi;
    }
};
