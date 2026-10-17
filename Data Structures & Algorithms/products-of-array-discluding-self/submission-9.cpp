class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n, 1), output(n, 1);
        int prefix = nums[0];
        for(int i = 1 ; i < n ; ++i){
            pre[i] = pre[i-1]*prefix;
            prefix = nums[i];
        }

        int postfix = nums[n-1];
        for(int i = n-2 ; i>=0 ; --i){
            output[i] = output[i+1] * postfix;
            postfix = nums[i];
        }

        for(int i = 0 ; i < n ; ++i){
            output[i] = output[i] * pre[i];
        }

        return output;
    }
};
