class Twitter {
public:
    int counter = 1;
    map<int, unordered_set<int>>mFollow;
    map<int, vector<pair<int, int>>>mPostTweet;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mPostTweet[userId].push_back({counter, tweetId});
        ++counter;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        mFollow[userId].insert(userId);
        unordered_set<int>s = mFollow[userId];
        for(auto it:s){
            vector<pair<int, int>>v1 = mPostTweet[it];
            for(int i = 0 ; i < v1.size() ; ++i){
                pq.push({v1[i].first, v1[i].second});
            }
        }
        int i = 0;
        vector<int>ans;
        while(i<10 && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
            ++i;
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        mFollow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        mFollow[followerId].erase(followeeId);
    }
};
