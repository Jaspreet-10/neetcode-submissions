class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
         unordered_map<char,int>m;
        priority_queue<int>pq;
        queue<pair<int,int>>q;
        int time = 0;
        for(int i = 0 ; i < tasks.size() ; ++i){
            m[tasks[i]]++;
        }
        for(auto it : m){
            pq.push(it.second);
        }
        while(!pq.empty() or !q.empty()){
            time+=1;
            if(!pq.empty()){
            int element = pq.top();
            element-=1;
            pq.pop();
            if(element>0){
                q.push({element, time+n});
            }
            }
            if(q.size() > 0 and q.front().second<=time){ 
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};
