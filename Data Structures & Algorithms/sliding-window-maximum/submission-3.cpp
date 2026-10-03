class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>ans;
        int temp = k;
        for(int i = 0 ; i < nums.size() ; ++i){
            while(!dq.empty() and nums[dq.back()]<nums[i]) dq.pop_back();
            dq.push_back(i);
            temp--;
            
            if(temp == 0){
                temp+=1;
                ans.push_back(nums[dq.front()]);
            }

            if(i - dq.front() + 1 >=k) dq.pop_front();
        }
        return ans;
    }
};
