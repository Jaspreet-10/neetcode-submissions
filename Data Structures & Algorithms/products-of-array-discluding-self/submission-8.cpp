class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pref(n, 1), output(n, 1);
        int pre = nums[0];
        for(int i = 1 ; i < n ; ++i){
            pref[i] = pref[i-1]*pre;
            pre = nums[i];
        }
        int post = nums[n-1];
        for(int i = n-2; i>=0 ; --i){
            output[i] = output[i+1]*post;
            post = nums[i];
        }
        for(int i = 0 ; i < n ; ++i){
            output[i]*=pref[i];
        }
        return output;
    }
};
