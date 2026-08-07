class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int prodLeft = 1, prodRight = 1, maxi = INT_MIN, i = 0, j = nums.size()-1;
        while(i<nums.size()){
            prodLeft = nums[i]*prodLeft;
            prodRight = nums[j]*prodRight;
            maxi = max(maxi, max(prodLeft, prodRight));
            if(prodLeft==0) prodLeft = 1;
            if(prodRight==0) prodRight = 1;
            ++i, --j;
        }
        return maxi;
    }
};
