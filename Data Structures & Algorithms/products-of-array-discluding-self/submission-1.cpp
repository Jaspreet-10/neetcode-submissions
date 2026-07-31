class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>pre(n, nums[0]);
        vector<int>post(n, nums[n-1]);
        vector<int>output(n, 0);
        for(int i = 1 ; i < n ; ++i){
            pre[i] = pre[i-1]*nums[i];
        }
         for(int i = n-2 ; i >= 0 ; --i){
            post[i] = post[i+1]*nums[i];
        }
        output[0] = post[1];
        output[n-1] = pre[n-2];
        for(int i = 1 ; i < n-1 ; ++i){
            output[i] = pre[i-1] * post[i+1];
        }
        return output;
    }
};
