class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int low = 0, high = m[key].size()-1;
        string ans = "";
        while(low<=high){
            int mid = (low + high)/2;
            if(m[key][mid].first<=timestamp){
                ans = m[key][mid].second;
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return ans;
    }
};
