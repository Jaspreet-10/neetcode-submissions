class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count = 0, n = intervals.size();
        if(n == 0) return 0;
        int left = 0, right = 1;
        sort(intervals.begin(), intervals.end());
        while(left<right && right<n){
            if(intervals[left][1]<=intervals[right][0]){
                left = right;
                ++right;
            }
            else if(intervals[left][1]>=intervals[right][1]){
                ++count;
                left = right;
                ++right;
            }
            else{
                ++count;
                ++right;
            }
        }
        return count;
    }
};
