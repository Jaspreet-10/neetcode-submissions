class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        unordered_map<int, int>m;
        vector<int>v;
        for(int i = 0 ; i < nums.size() ; ++i){
            m[nums[i]]++;
        }
        for(auto it : m){
            pq.push({it.second, it.first});
        }
        while(k>0){
            v.push_back(pq.top().second);
            pq.pop();
            --k;
        }
        return v;
    }
};
