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
        if(intervals.size() == 0) return true;
        vector<pair<int,int>>v;
        for(int i = 0 ; i < intervals.size() ; ++i){
            v.push_back({intervals[i].end, intervals[i].start});
        }
        sort(v.begin(),v.end());
        int s = v[0].second;
        int e = v[0].first;
        for(int i = 1 ; i < v.size() ; ++i){
            if(v[i].second>=e){
                e = v[i].first;
            }else return false;
        }
        return true;
    }
};
