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
        int e = v[0].first;
        int s = v[0].second;
        for(int i = 1 ; i < intervals.size() ; ++i){
            if(e<=v[i].second){
                e = v[i].first;
            }else return false;
        }
        return true;
    }
};
