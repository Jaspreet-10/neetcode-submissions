class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int temp = k;
        deque<int>dq;
        vector<int>result;

        for(int i = 0 ; i < nums.size() ; ++i){
            while(!dq.empty() and nums[dq.back()]<nums[i]) dq.pop_back();

            dq.push_back(i);

            --k;
            if(k == 0){
                result.push_back(nums[dq.front()]);
                ++k;
            }

            if(i - dq.front()+1>=temp) dq.pop_front();
        }

        return result;
    }
};
