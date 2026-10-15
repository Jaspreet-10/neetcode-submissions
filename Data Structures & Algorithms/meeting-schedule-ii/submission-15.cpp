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
        vector<int>s,e;
        int n = intervals.size();
        if(n == 0) return 0;
        for(int i = 0 ; i < n ; ++i){
            s.push_back(intervals[i].start);
            e.push_back(intervals[i].end);
        }

        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int st = 1, en = 0, count = 1;
        while(st<n and en<n){
            if(s[st]<e[en]){
                ++st, ++count;
            }
            else{
                ++st;
                ++en;
            }
        }
        return count;
    }
};
