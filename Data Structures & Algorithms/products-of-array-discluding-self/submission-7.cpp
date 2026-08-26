class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prefix = nums[0], post = nums[n-1];
        vector<int>output(n, 1);
        for(int i = 1 ; i < n ; ++i){
            output[i] = prefix;
            prefix = output[i]*nums[i];
        }
        int postfix = nums[n-1];
        for(int i = n-2 ; i>=0 ; --i){
            output[i]*=postfix;
            postfix*=nums[i];

        }
        return output;
    }
};
