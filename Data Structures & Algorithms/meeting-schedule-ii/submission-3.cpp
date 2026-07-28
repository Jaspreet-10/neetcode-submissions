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
        if(intervals.size() == 0) return 0;
        vector<int>s,e;
        for(int i = 0 ; i < intervals.size() ; ++i){
            s.push_back(intervals[i].start);
            e.push_back(intervals[i].end);
        }
        sort(s.begin(),s.end());
        sort(e.begin(),e.end());
        int i = 1 , j = 0, cnt = 1;
        while(i<s.size()){
            if(s[i]>=e[j]){
                ++i;
                ++j;
            }else{
                ++i;
                ++cnt;
            }
        }
        return cnt;
    }
};
