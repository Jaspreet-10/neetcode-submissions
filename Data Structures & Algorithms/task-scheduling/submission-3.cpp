class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>m;
        priority_queue<int>pq;
        queue<pair<int, int>>q;
        int time = 0;
        for(int i = 0 ; i < tasks.size() ; ++i) m[tasks[i]]++;

        for(auto it : m) pq.push(it.second);

        while(!pq.empty() or !q.empty()){
            int t = 0;
            if(!pq.empty()){
            t = pq.top();
            pq.pop();
            t--;
            }
            
            if(t!=0) q.push({t, time+n});

            if(!q.empty()){
                if(q.front().second<=time){
                    pq.push(q.front().first);
                    q.pop();
                }
            }
            ++time;
        }
        return time;
    }
};
