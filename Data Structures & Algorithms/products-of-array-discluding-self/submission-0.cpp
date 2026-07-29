class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> preFix(n, nums[0]), postFix(n, nums[n - 1]), output(n, 0);
        preFix[0] = 1;
        for (int i = 1; i < n; i++) preFix[i] = preFix[i - 1] * nums[i - 1];

        postFix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) postFix[i] = postFix[i + 1] * nums[i + 1];

        for (int i = 0; i < n; i++) output[i] = preFix[i] * postFix[i];
        return output;
    }
};
