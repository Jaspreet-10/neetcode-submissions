class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int left = 0, right = 1, n = intervals.size(), count = 0;
        sort(intervals.begin(), intervals.end());
        while(left<n and right<n){
            if(intervals[left][1]<=intervals[right][0]){
                left = right;
                ++right;
            }
            else if(intervals[left][1]<intervals[right][1]){
                ++right, ++count;
            }
            else{
                left = right;
                ++right, ++count;
            }
        }
        return count;
    }
};
