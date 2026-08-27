class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        deque<int>dq;
        int temp = k;
        for(int i = 0 ; i < nums.size() ; ++i){
            while(!dq.empty() && nums[dq.front()]<nums[i]) dq.pop_front();
            dq.push_front(i);
            --k;
            if(k == 0){
                ans.push_back(nums[dq.back()]);
                ++k;
            }
            if((i - dq.back()+1)>=temp){
                    dq.pop_back();
                }
            }
        return ans;
    }
};
