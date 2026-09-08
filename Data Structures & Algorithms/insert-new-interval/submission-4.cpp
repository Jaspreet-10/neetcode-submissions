class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>ans;
        intervals.push_back(newInterval);
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        int a = intervals[0][0], b =intervals[0][1];
        for(int i = 1 ; i < intervals.size() ; ++i){
            if(intervals[i][0]<=b){
                b = max(b, intervals[i][1]);
            }else{
                ans.push_back({a, b});
                a = intervals[i][0];
                b = intervals[i][1];
            }
        }
        ans.push_back({a, b});
        return ans;
    }
};
