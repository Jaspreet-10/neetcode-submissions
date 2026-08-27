class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        stack<double>st;
        vector<pair<int, int>>v;
        for(int i = 0 ; i < n ; ++i){
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        for(int i = 0 ; i < n ; ++i){
            double t = (double)((target - v[i].first)/(v[i].second*1.0));
            while(!st.empty() and st.top()<=t) st.pop();
            st.push(t);
        }
        return st.size();
    }
};
