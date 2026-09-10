class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        bool flag = true;
        while(flag || slow!=fast){
            slow = nums[slow];
            fast = nums[nums[fast]];
            flag = false;
        }   
        fast = nums[0];
        while(slow!=fast){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
