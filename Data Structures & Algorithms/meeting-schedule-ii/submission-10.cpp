/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.size() == 0) return false;
        int n = intervals.size(), count = 1;
        vector<int>s(n, 0), e(n, 0);
        for(int i = 0 ; i < n ; ++i){
           s[i] = intervals[i].start;
           e[i] = intervals[i].end;
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        int start = 1, end = 0;
        while(start<n && end<n){
            if(s[start]<e[end]){
                ++count;
                ++start;
            }else{
                ++start, ++end;
            }
        }
        return count;
    }
};
