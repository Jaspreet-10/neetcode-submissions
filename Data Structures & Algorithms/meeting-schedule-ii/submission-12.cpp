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
        vector<int>start, end;
        int n = intervals.size();
        if(n == 0) return 0;
        for(int i = 0 ; i < n ; ++i){
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int i = 1, j = 0, count = 1;
        while(i<n and j<n){
            if(start[i]<end[j]){
                ++i, ++count;
            }
            else{
                ++i, ++j;
            }
        }
        return count;
    }
};
