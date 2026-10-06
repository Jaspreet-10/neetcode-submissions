class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int left = 0, right = 1, n = intervals.size(), count = 0;
        
        while(right<n){
            if(intervals[right][0]>=intervals[left][1]){
                left = right;
                right+=1;
            }

            else if(intervals[right][1]<intervals[left][1]){
                left = right;
                ++right;
                ++count;
            }
            else{
                right+=1;
                ++count;
            }
        }
        return count;
    }
};
