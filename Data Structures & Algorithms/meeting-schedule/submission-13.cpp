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
        int n = intervals.size();
        vector<pair<int, int>>v;
        for(int i = 0 ; i < n ; ++i){
            v.push_back({intervals[i].start, intervals[i].end});
        }
        sort(v.begin(), v.end());
        int a = v[0].first, b = v[0].second;

        for(int i = 1 ; i < n ; ++i){
            if(v[i].first<b){
                return false;
            }else{
                a = v[i].first;
                b = v[i].second;
            }
        }
        
        return true;
    }
};
