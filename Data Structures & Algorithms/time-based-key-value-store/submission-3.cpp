class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!m.count(key)) return "";
        vector<pair<int, string>>&v = m[key];
        int start = 0, end = v.size()-1, ans = -1;
        while(start<=end){
            int mid = start + (end - start) / 2;
            if(v[mid].first<=timestamp){
                ans = mid;
                start = mid+1;
            }
            else end = mid-1;
        }
        return ans == -1? "" : v[ans].second;
    }
};
