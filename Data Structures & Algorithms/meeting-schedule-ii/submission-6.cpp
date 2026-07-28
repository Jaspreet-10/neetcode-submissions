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
        vector<int>start,end;
        int count = 1, i = 1, j = 0;
        for(int i = 0 ; i < intervals.size() ; ++i){
           start.push_back(intervals[i].start);
           end.push_back(intervals[i].end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        while(i<start.size()){
            if(start[i]>=end[j]){
                ++i,++j;
            }else{
                ++count;
                ++i;
            }
        }
        return count;
    }
};
