class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n = t.size();
        vector<int>v(n, 0);
        stack<int>st;
        for(int i = 0 ; i < n ; ++i){
            while(!st.empty() and t[st.top()]<t[i]){
                v[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        return v;
    }
};
