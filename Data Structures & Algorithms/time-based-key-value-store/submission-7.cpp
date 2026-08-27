class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int low = 0, high = m[key].size()-1, ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            // if(timestamp == v[mid].first) str = v[mid].second;
            if(timestamp>=m[key][mid].first){
                ans = mid;
                low = mid+1;
            } 
            else high = mid-1;
        }
        return ans == -1 ? "" : m[key][ans].second;
    }
};
