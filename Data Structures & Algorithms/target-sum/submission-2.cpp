class Solution {
public:
    int findTarget(int index, int n, vector<int>&nums, int target, 
        map<pair<int, int>, int>&m){
        if(target == 0 and index == n) return 1;
        if(index>=n and target!=0) return 0;
        if(m.find({index, target})!=m.end()) return m[{index, target}];
        int sub = -nums[index] + findTarget(index+1, n, nums, 
        target - nums[index], m);
        int add = nums[index] + findTarget(index+1, n, nums, 
        target + nums[index], m);
        return m[{index, target}] = sub + add;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        map<pair<int, int>, int>m;
        return findTarget(0, n, nums, target, m);
    }
};
