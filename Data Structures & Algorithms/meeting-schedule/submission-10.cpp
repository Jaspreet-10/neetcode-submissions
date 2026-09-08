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
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<vector<int>>v;
        for(int i = 0 ; i < intervals.size() ; ++i){
            v.push_back({intervals[i].start, intervals[i].end});
        }
        sort(v.begin(), v.end());
        for(int i = 1 ; i < v.size() ; ++i){
           if(v[i][0]<v[i-1][1]) return false;
        }
        return true;
    }
};
