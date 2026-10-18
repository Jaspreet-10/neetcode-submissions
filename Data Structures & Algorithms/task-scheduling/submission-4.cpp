class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int>m;
        priority_queue<int>pq;
        queue<pair<int, int>>q;
        int time = 0;
        for(int i = 0 ; i < tasks.size() ; ++i){
            m[tasks[i]]++;
        }

        for(auto it : m){
            pq.push(it.second);
        }

        while(!pq.empty() || !q.empty()){
            int count = 0;
            if(!pq.empty()){
            count = pq.top();
            pq.pop();
            count-=1;
            }
            if(count>0){
                q.push({count, time+n});
            }
            if(!q.empty() and q.front().second<=time){
                pq.push(q.front().first);
                q.pop();
            }
            time+=1;
        }
        return time;
    }
};
