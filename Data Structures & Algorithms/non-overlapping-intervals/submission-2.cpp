class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());    //Sort all intervals in ASC order
        int count = 0;      //Count of number of intervals to be removed
        int n = intervals.size();   //No of intervals
        int left = 0;   //left interval
        int right = 1;  //right interval
        
        while(right<n){
            if(intervals[left][1]<=intervals[right][0]){
                left = right;
                right+=1;
            }
            else if(intervals[left][1]>=intervals[right][1]){
                count+=1;
                left = right;
                right+=1;
            }
            else{
                 count+=1;
                 right+=1;
            }
        }
        return count;
    }
};
