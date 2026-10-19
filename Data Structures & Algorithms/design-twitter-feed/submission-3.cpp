class Twitter {
public:
    unordered_map<int, unordered_set<int>>mFollow;
    unordered_map<int, vector<pair<int, int>>>mPost;
    int time = 0;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        mPost[userId].push_back({time, tweetId});
        time+=1;
    }
    
    vector<int> getNewsFeed(int userId) {
        mFollow[userId].insert(userId);
        vector<int>ans;
        priority_queue<pair<int, int>>pq;
        for(auto it : mFollow[userId]){
            vector<pair<int, int>>v = mPost[it];
            for(int i = 0 ; i < v.size() ; ++i){
                pq.push(v[i]);
            }
        }
        int i = 0;
        while(i < 10 and !pq.empty()){
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
