class Solution {
   public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> res;
        priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>,
                       greater<pair<double, pair<int, int>>>>
            pq;
        for (int i = 0; i < points.size(); ++i) {
            int x = points[i][0], y = points[i][1];
            pq.push({sqrt(x * x + y * y), {x, y}});
        }
        while (k > 0 and !pq.empty()) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
            --k;
        }
        return res;
    }
};
