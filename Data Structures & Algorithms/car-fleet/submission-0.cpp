class Solution {
   public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> v;
        stack<double> st;
        for (int i = 0; i < position.size(); ++i) {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            double num = (double(target - v[i].first) / (v[i].second * 1.0));
            while (!st.empty() && st.top() <= num) st.pop();
            st.push(num);
        }
        return st.size();
    }
};
