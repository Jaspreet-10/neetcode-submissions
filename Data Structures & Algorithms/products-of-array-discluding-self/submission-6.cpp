class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), prefix = nums[0], post = nums[n-1];
        vector<int>output(n, 0);
        vector<int>pre(n, 0);
        pre[0] = 1;
        for(int i = 1 ; i < n ; ++i){
            pre[i] = prefix;
            // cout<<pre[i]<<" ";
            prefix*=nums[i];
        }
        output[n-1] = pre[n-1];
        for(int i = n-2 ; i>0 ; --i){
            output[i] = pre[i]*post;
            post*=nums[i];

        }
        output[0] = post;
        return output;
    }
};
